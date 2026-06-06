#include <vector>
using namespace std;

bool judgeWinnability(int stonesCount) // LeetCode Q.1510.
{
    vector<int> squaresCounts(stonesCount + 1, 0);

    for (int num = 1; num <= stonesCount; num++) {
        int maxSqrt = static_cast<int>(pow(num, 0.5));

        if (pow(maxSqrt, 2) == num) {
            squaresCounts[num] += 1; // From 0 to 1.
            continue;
        }

        for (int sqrt = maxSqrt; sqrt >= 1; sqrt--) {
            int residual = num - pow(sqrt, 2);
            if (squaresCounts[residual] == 0) {
                squaresCounts[num] += 1; // From 0 to 1.
                break;
            }
        }
    }

    return squaresCounts.back() == 1;
}
