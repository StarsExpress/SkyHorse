
class LongestCycle:  # LeetCode Q.2360.
    def __init__(self):
        self.edges: list[int] = []
        self.visited_orders: list[int] = []

        self.current_order = 1
        self.longest_cycle = -1

    def _dfs_cycle(self, node: int) -> None:
        self.visited_orders[node] = self.current_order
        self.current_order += 1  # Increment for the next node.

        tgt_node = self.edges[node]
        if tgt_node == -1:  # No outgoing edge.
            self.visited_orders[node] = -2  # Current node finalizes DFS.
            return

        if self.visited_orders[tgt_node] == -1:  # Unvisited yet.
            self._dfs_cycle(tgt_node)

        tgt_node_order = self.visited_orders[tgt_node]

        # Target node still under DFS: a cycle just forms.
        if tgt_node_order > 0:
            # Such a cycle starts at target, and ends at current node.
            cycle_len = self.visited_orders[node] + 1 - tgt_node_order
            if cycle_len > self.longest_cycle:
                self.longest_cycle = cycle_len

        self.visited_orders[node] = -2  # Current node finalizes DFS.

    def compute_longest_cycle_len(self, edges: list[int]) -> int:
        self.edges = edges

        # Special marks: -1 = unvisited yet. -2 = has finalized DFS.
        self.visited_orders = [-1] * len(edges)

        self.current_order = 1
        self.longest_cycle = -1

        for node, _ in enumerate(edges):
            if self.visited_orders[node] == -1:  # Unvisited yet.
                self._dfs_cycle(node)

        return self.longest_cycle
