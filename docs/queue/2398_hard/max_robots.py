from collections import deque


def count_max_robots(charge_times: list[int], running_costs: list[int], budget: int):  # LeetCode Q.2398.
    max_robots_count = 0  # Base case.

    window_total_cost = 0

    queue: deque[tuple[int, int]] = deque([])  # Format: (charge time, idx).

    start_idx = 0
    for end_idx, charge_time in enumerate(charge_times):
        window_total_cost += running_costs[end_idx]

        while queue and queue[-1][0] <= charge_time:
            queue.pop()

        queue.append((charge_time, end_idx))

        robots_count = end_idx + 1 - start_idx
        max_charge_time = queue[0][0]

        while budget < max_charge_time + robots_count * window_total_cost:
            window_total_cost -= running_costs[start_idx]

            robots_count -= 1
            start_idx += 1

            if queue and queue[0][1] < start_idx: queue.popleft()

            if start_idx > end_idx: break  # 0 robots at hand.

        if robots_count > max_robots_count: max_robots_count = robots_count

    return max_robots_count
