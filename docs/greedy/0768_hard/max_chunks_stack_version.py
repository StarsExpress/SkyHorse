
def find_max_sortable_chunks(nums: list[int]) -> int:  # LeetCode Q.768 & 769.
    stack: list[int] = []

    for num in nums:
        if not stack:
            stack.append(num)
            continue

        chunk_max = stack[-1]
        
        while stack and stack[-1] > num:
            stack.pop(-1)
        
        stack.append(max(chunk_max, num))

    return len(stack)
