#include <cmath>
#include <vector>
using namespace std;

int countPossibilities(int recordLen) // LeetCode Q.552.
{
    // Possible ends: "P", "L", "LL".
    long long noAbsEndP = 1, noAbsEndL = 1, noAbsEndLL = 0;

    // Possible ends: "P", "L", "LL", "A".
    long long oneAbsEndP = 0, oneAbsEndL = 0, oneAbsEndLL = 0, oneAbsEndA = 1;

    // Helper variables: help each day's branch counts update values.
    long long newNoAbsEndP = 0, newNoAbsEndL = 0, newNoAbsEndLL = 0;

    long long newOneAbsEndP = 0, newOneAbsEndL = 0, newOneAbsEndLL = 0, newOneAbsEndA = 0;

    long long modulo = pow(10, 9) + 7; // Long long prevents overflow.

    for (int day = 2; day <= recordLen; day++) {
        long long noAbsSum = noAbsEndP + noAbsEndL + noAbsEndLL;
        noAbsSum %= modulo;

        newNoAbsEndP = noAbsSum % modulo; // No.1: all 0 absence ends are now "P".

        newNoAbsEndL = noAbsEndP; // No.2: 0 absence end "P" => "L".
        newNoAbsEndLL = noAbsEndL; // No.3: 0 absence end "L" => "LL".

        long long oneAbsSum = oneAbsEndP + oneAbsEndL + oneAbsEndLL + oneAbsEndA;
        oneAbsSum %= modulo;

        newOneAbsEndP = oneAbsSum % modulo; // No.4: all 1 absence ends are now "P".

        // No.5: 1 absence end from "P" or "A" to "L".
        newOneAbsEndL = (oneAbsEndP + oneAbsEndA) % modulo;

        newOneAbsEndLL = oneAbsEndL; // No.6: 1 absence end "l" => "ll".

        newOneAbsEndA = noAbsSum % modulo; // No.7: from 0 to 1 absence.

        // Transit updated counts.
        noAbsEndP = newNoAbsEndP, noAbsEndL = newNoAbsEndL, noAbsEndLL = newNoAbsEndLL;

        oneAbsEndP = newOneAbsEndP, oneAbsEndL = newOneAbsEndL;
        oneAbsEndLL = newOneAbsEndLL, oneAbsEndA = newOneAbsEndA;

        // Reset helper variables for next day's usage.
        newNoAbsEndP = 0, newNoAbsEndL = 0, newNoAbsEndLL = 0;

        newOneAbsEndP = 0, newOneAbsEndL = 0, newOneAbsEndLL = 0, newOneAbsEndA = 0;
    }

    long long validCounts = (noAbsEndP + noAbsEndL + noAbsEndLL) % modulo;

    validCounts += (oneAbsEndP + oneAbsEndL + oneAbsEndLL + oneAbsEndA) % modulo;

    return validCounts % modulo;
}
