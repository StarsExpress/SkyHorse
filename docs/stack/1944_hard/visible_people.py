
def count_visibilities(heights: list[int]) -> list[int]:  # LeetCode Q.1944.
    stack = []
    visibilities = [0] * len(heights)

    for idx in range(len(heights) - 1, -1, -1):  # Backward iteration.
        height = heights[idx]
        
        while stack and stack[-1] < height:  # People on my left side can't see them.
            stack.pop(-1)
            visibilities[idx] += 1  # I can see unblocked shorter people.

        if stack:  # I can always see my next non-shorter person (if exists).
            visibilities[idx] += 1

            if stack[-1] == height:  # People on my left side can't see this person.
                stack.pop(-1)
        
        stack.append(height)

    return visibilities
