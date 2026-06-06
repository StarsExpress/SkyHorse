
def judge_winnability(stones_count: int) -> bool:  # LeetCode Q.1510.
    squares_counts = [0] * (stones_count + 1)

    for num in range(1, stones_count + 1):
        max_sqrt = int(num ** 0.5)
        if max_sqrt ** 2 == num:
            squares_counts[num] += 1  # From 0 to 1.
            continue

        for sqrt in range(max_sqrt, 0, -1):
            residual = num - (sqrt ** 2)
            if squares_counts[residual] == 0:
                squares_counts[num] += 1  # From 0 to 1.
                break

    return squares_counts[-1] == 1
