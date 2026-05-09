import heapq


def reorganize_string(init_string: str) -> str:  # LeetCode Q.767.
    chars_counts: dict[str, int] = dict()

    for char in init_string:
        if char not in chars_counts.keys():
            chars_counts.update({char: 0})
        chars_counts[char] += 1

        # Sanity check.
        if chars_counts[char] > (len(init_string) + 1) / 2: return ""

    max_heap: list[tuple[int, str]] = []  # Format: (count, char).

    for char, count in chars_counts.items():
        heapq.heappush(max_heap, (-count, char))  # Negate count to fit max heap.

    reshaped_string = ""

    while len(max_heap) > 1:
        top_1_count, top_1_char = heapq.heappop(max_heap)
        top_1_count = -top_1_count  # Negate back to original value.

        top_2_count, top_2_char = heapq.heappop(max_heap)
        top_2_count = -top_2_count  # Negate back to original value.

        reshaped_string += top_1_char + top_2_char

        if top_1_count > 1:  # Negate count to fit max heap.
            heapq.heappush(max_heap, (1 - top_1_count, top_1_char))

        if top_2_count > 1:  # Negate count to fit max heap.
            heapq.heappush(max_heap, (1 - top_2_count, top_2_char))

    if max_heap: reshaped_string += max_heap[-1][1]

    return reshaped_string
