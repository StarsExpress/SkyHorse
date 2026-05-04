
class MaxFrequencyStack:  # LeetCode Q.895.
    def __init__(self):
        self.vals_freqs: dict[int, int] = dict()

        # Each idx contains stack of values w/ frequency = idx.
        # Pad empty stack to adjust for 0-based indexing.
        self.freqs_stacks: list[list[int]] = [[]]
    
    def push(self, value: int) -> None:
        if value not in self.vals_freqs.keys():
            self.vals_freqs.update({value: 0})
        self.vals_freqs[value] += 1

        # Need to add another stack for current frequency.
        if self.vals_freqs[value] == len(self.freqs_stacks):
            self.freqs_stacks.append([])

        frequency = self.vals_freqs[value]
        self.freqs_stacks[frequency].append(value)

    def pop(self) -> int:
        most_freq_val = self.freqs_stacks[-1].pop(-1)

        if not self.freqs_stacks[-1]: self.freqs_stacks.pop(-1)

        self.vals_freqs[most_freq_val] -= 1
        return most_freq_val
