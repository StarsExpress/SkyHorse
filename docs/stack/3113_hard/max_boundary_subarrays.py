
def count_subarrays(nums: list[int]) -> int:  # LeetCode Q.3113.
    stack: list[tuple[int, int]] = []  # Format: (num, count).

    subarrays_count = 0

    for num in nums:
        while stack and stack[-1][0] < num:
            stack.pop(-1)
        
        count = 1  # Base case: current num only.

        if stack and stack[-1][0] == num:
            count += stack.pop(-1)[1]

        subarrays_count += count
        stack.append((num, count))

    return subarrays_count
