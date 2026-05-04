#include <vector>
#include <unordered_map>
using namespace std;

int countGoodPartitions(vector<int> &nums) // LeetCode Q.2963.
{
    unordered_map<int, int> numsLastIndices; // Each num's last idx.

    for (int idx = 0; idx < nums.size(); idx++)
        numsLastIndices[nums[idx]] = idx;

    int windowsCount = 0; // Sliding window by two pointers.
    int scanIdx = 0, boundaryIdx = 0;

    while (boundaryIdx < nums.size())
    {
        int num = nums[scanIdx];
        scanIdx++; // Already visited.

        if (boundaryIdx < numsLastIndices[num])
        { // Num extends current window.
            boundaryIdx = numsLastIndices[num];
            continue;
        }

        if (scanIdx > boundaryIdx)
        {
            windowsCount++; // Current window is finalized.

            boundaryIdx++; // Search for another window, if possible.
        }
    }

    int goodPartitions = 1;

    int power = windowsCount - 1, modulo = pow(10, 9) + 7;

    while (power > 0)
    {
        goodPartitions *= 2;
        goodPartitions %= modulo; // Must prevent overflow.
        power--;
    }

    return goodPartitions;
}
