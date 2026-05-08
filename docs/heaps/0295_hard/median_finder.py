import heapq


class MedianFinder:  # LeetCode Q.295.
    def __init__(self):
        # When nums count is odd, median goes to min heap.
        # Max heap needs to negate value to fit default Python min heap.
        self.min_heap: list[int] = []
        self.max_heap: list[int] = []

    def add_num(self, num: int):
        if len(self.max_heap) == len(self.min_heap):
            heapq.heappush(self.min_heap, num)

        else:
            heapq.heappush(self.max_heap, -num)  # Max heap negates.

        while self.max_heap and self.min_heap:
            if -self.max_heap[0] <= self.min_heap[0]: break  # No need to adjust.

            # -Max heap top > min heap top: mismatch so must switch.
            former_max_heap_top = -heapq.heappop(self.max_heap)  # Max heap negates.
            heapq.heappush(self.min_heap, former_max_heap_top)

            former_min_heap_top = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -former_min_heap_top)  # Max heap negates.

    def find_median(self):
        if len(self.min_heap) > len(self.max_heap):
            return self.min_heap[0]

        return (self.min_heap[0] - self.max_heap[0]) / 2  # Max heap negates.
