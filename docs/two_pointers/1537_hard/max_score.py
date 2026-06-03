
def find_max_score(nums_1: list[int], nums_2: list[int]) -> int:  # LeetCode Q.1537.
    max_score = 0
    modulo = 10 ** 9 + 7

    score_1, score_2 = 0, 0

    idx_1, idx_2 = 0, 0

    while idx_1 < len(nums_1) and idx_2 < len(nums_2):
        while idx_1 < len(nums_1) and nums_1[idx_1] < nums_2[idx_2]:
            score_1 += nums_1[idx_1]
            idx_1 += 1
        
        if idx_1 == len(nums_1): break  # Array 1 can't catch up.

        while idx_2 < len(nums_2) and nums_2[idx_2] < nums_1[idx_1]:
            score_2 += nums_2[idx_2]
            idx_2 += 1
        
        if idx_2 == len(nums_2): break  # Array 2 can't catch up.

        if nums_1[idx_1] == nums_2[idx_2]:  # Arrays can now compare scores.
            score_1 += nums_1[idx_1]
            score_2 += nums_2[idx_2]

            max_score += max(score_1, score_2)
            if max_score > modulo: max_score %= modulo  # Control size.
            
            score_1, score_2 = 0, 0  # Reset for next while iteration.
            idx_1 += 1
            idx_2 += 1

    while idx_1 < len(nums_1):  # Remaining nums from array 1.
        score_1 += nums_1[idx_1]
        idx_1 += 1

    while idx_2 < len(nums_2):  # Remaining nums from array 2.
        score_2 += nums_2[idx_2]
        idx_2 += 1

    max_score += max(score_1, score_2)
    return max_score % modulo  # Control size.
