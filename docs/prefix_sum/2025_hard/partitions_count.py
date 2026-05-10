
def count_max_partitions(nums: list[int], k: int) -> int:  # LeetCode Q.2025.
    # Left diff: only consider potential pivot indices at left side.
    # Right diff: only consider potential pivot indices at right side.
    # Dict key: diff = prefix sum - suffix sum.
    left_diff_counts: dict[int, int] = dict()
    right_diff_counts: dict[int, int] = dict()

    # Default to natural value: leave entire array unchanged.
    max_partition_ways = 0

    total_sum = sum(nums)
    prefix_sum = 0

    for pivot_idx in range(1, len(nums)):
        prefix_sum += nums[pivot_idx - 1]
        suffix_sum = total_sum - prefix_sum
        diff = prefix_sum - suffix_sum

        if diff not in right_diff_counts.keys():
            right_diff_counts[diff] = 0
        right_diff_counts[diff] += 1

        # Born as a great partition. No need to change.
        if prefix_sum == suffix_sum: max_partition_ways += 1

    prefix_sum = 0  # Reset to let next for loop sweep again.

    for idx, num in enumerate(nums):
        prefix_sum += num

        partition_ways = 0

        # Potential pivot idx is at the right of current idx.
        partition_ways += right_diff_counts.get(num - k, 0)

        # Potential pivot idx is at the left of current idx.
        partition_ways += left_diff_counts.get(k - num, 0)

        if partition_ways > max_partition_ways:
            max_partition_ways = partition_ways

        diff = 2 * prefix_sum - total_sum  # Prefix - suffix.
        # For future indices, this diff is only available as left side.

        if diff not in left_diff_counts.keys():
            left_diff_counts[diff] = 0
        left_diff_counts[diff] += 1

        if diff in right_diff_counts.keys():
            right_diff_counts[diff] -= 1

    return max_partition_ways
