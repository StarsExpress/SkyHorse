
def count_subarray_scores(nums: list[int], k: int) -> int:  # LeetCode Q.2302.
    total_subarrays = 0
    subarray_sum = 0

    start_idx = 0
    for end_idx, num in enumerate(nums):
        subarray_sum += nums[end_idx]
        score = subarray_sum * (end_idx + 1 - start_idx)

        while score >= k and start_idx <= end_idx:
            subarray_sum -= nums[start_idx]
            start_idx += 1
            score = subarray_sum * (end_idx + 1 - start_idx)

        total_subarrays += end_idx + 1 - start_idx

    return total_subarrays
