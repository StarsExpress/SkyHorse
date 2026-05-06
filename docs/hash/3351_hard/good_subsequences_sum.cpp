#include <vector>
#include <unordered_map>
using namespace std;

int sumGoodSubsequences(vector<int> &nums) // LeetCode Q.3351.
{
    long long modulo = pow(10, 9) + 7; // Long long prevents overflow.

    unordered_map<int, long long> subseqCounts, subseqSums;

    for (const auto &num : nums)
    {
        for (const auto &validTail : {num - 1, num + 1})
        {
            long long prevCount = subseqCounts[validTail];
            subseqCounts[num] += prevCount;

            long long prevSum = subseqSums[validTail];
            subseqSums[num] += prevSum + num * prevCount;
        }

        // Counts & sums are O(2^n) so must do modulo for future operations.
        subseqCounts[num] += 1;
        if (subseqCounts[num] > modulo)
            subseqCounts[num] %= modulo;

        subseqSums[num] += num;
        if (subseqSums[num] > modulo)
            subseqSums[num] %= modulo;
    }

    long long goodSubseqSum = 0;
    for (const auto &pair : subseqSums)
        goodSubseqSum += pair.second;

    return goodSubseqSum % modulo; // Control value size.
}