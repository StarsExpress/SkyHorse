
def find_max_sortable_chunks(nums: list[int]) -> int:  # LeetCode Q.768 & 769.
    prefix_maxs = []  # Max of each arr[:(i + 1)th idx].

    for num in nums:
        if not prefix_maxs:
            prefix_maxs.append(num)
            continue

        prefix_maxs.append(
            max(num, prefix_maxs[-1])
        )

    max_chunks = 1  # Base case.
    suffix_min = nums[-1]  # Min of arr[ith idx:].

    for idx in range(len(nums) - 1, 0, -1):
        if nums[idx] < suffix_min:
            suffix_min = nums[idx]

        if prefix_maxs[idx - 1] <= suffix_min:
            max_chunks += 1

    return max_chunks
