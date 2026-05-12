#include <vector>
using namespace std;

int findMaxSortableChunks(vector<int>& nums) // LeetCode Q.768 & 769.
{
    vector<int> prefixMaxs; // Max of each arr[:(i + 1)th idx].

    for (const auto& num : nums) {
        if (prefixMaxs.empty()) {
            prefixMaxs.push_back(num);
            continue;
        }

        prefixMaxs.push_back(max(prefixMaxs.back(), num));
    }

    int maxChunks = 1; // Base case.
    int suffixMin = nums.back(); // Min of arr[ith idx:].

    for (int idx = nums.size() - 1; idx >= 1; idx--) {
        if (nums[idx] < suffixMin)
            suffixMin = nums[idx];

        if (prefixMaxs[idx - 1] <= suffixMin)
            maxChunks++;
    }

    return maxChunks;
}
