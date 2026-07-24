from collections import deque


def find_min_reorders(n: int, connections: list[list[int]]) -> int:
    src_nodes: list[list[int]] = [[] for _ in range(n)]  # Each node's source nodes.
    tgt_nodes: list[list[int]] = [[] for _ in range(n)]  # Each node's target nodes.

    visited: list[bool] = [False] * n

    for src_node, tgt_node in connections:
        src_nodes[tgt_node].append(src_node)
        tgt_nodes[src_node].append(tgt_node)

    min_reorders = 0
    queue: deque[int] = deque([0])  # Stores nodes.

    while queue:
        node = queue.popleft()
        visited[node] = True

        for src_node in src_nodes[node]:
            if not visited[src_node]:
                queue.append(src_node)

        for tgt_node in tgt_nodes[node]:
            if not visited[tgt_node]:
                min_reorders += 1
                queue.append(tgt_node)

    return min_reorders
