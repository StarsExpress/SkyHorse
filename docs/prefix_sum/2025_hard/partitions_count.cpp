#include <vector>
#include <unordered_map>
using namespace std;

int countMaxPartitions(vector<int> &nums, int k) // LeetCode Q.2025.
{
    long long totalSum = 0; // Prevents overflow.
    for (const auto &num : nums)
        totalSum += num;

    // Left diff: only consider potential pivot indices at left side.
    // Right diff: only consider potential pivot indices at right side.
    // Map key: diff = prefix sum - suffix sum.
    unordered_map<long long, int> leftDiffCounts, rightDiffCounts;

    // Default to natural value: leave entire array unchanged.
    int maxPartitionWays = 0;

    long long prefixSum = 0;
    for (int pivotIdx = 1; pivotIdx < nums.size(); pivotIdx++)
    {
        prefixSum += nums[pivotIdx - 1];
        long long suffixSum = totalSum - prefixSum;
        rightDiffCounts[prefixSum - suffixSum]++;

        // Born as a great partition. No need to change.
        if (prefixSum == suffixSum)
            maxPartitionWays++;
    }

    prefixSum = 0; // Reset to let next for loop sweep again.

    for (int idx = 0; idx < nums.size(); idx++)
    {
        int num = nums[idx];
        prefixSum += num;

        int partitionWays = 0;

        // Potential pivot idx is at the right of current idx.
        partitionWays += rightDiffCounts[num - k];

        // Potential pivot idx is at the left of current idx.
        partitionWays += leftDiffCounts[k - num];

        if (partitionWays > maxPartitionWays)
            maxPartitionWays = partitionWays;

        long long diff = 2 * prefixSum - totalSum; // Prefix - suffix.

        // For future indices, this diff is only available as left side.
        leftDiffCounts[diff]++;
        rightDiffCounts[diff]--;
    }

    return maxPartitionWays;
}
