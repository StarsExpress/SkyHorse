---
title: "768. Max Chunks"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCodePrefix from '@site/docs/greedy/0768_hard/max_chunks_prefix_version.cpp?raw';
import PyCodePrefix from '@site/docs/greedy/0768_hard/max_chunks_prefix_version.py?raw';
import CppCodeStack from '@site/docs/greedy/0768_hard/max_chunks_stack_version.cpp?raw';
import PyCodeStack from '@site/docs/greedy/0768_hard/max_chunks_stack_version.py?raw';


## [Max Chunks To Make Sorted II](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/)
This problem carries a very peculiar feeling for me:

a sense that things have changed while the problem remains the same.

I solved it for the first time in late 2024 and got AC.

Coming back in early 2026, I got AC again.

But these two solutions are based on different data structures.


## I. Late 2024: Prefix and Suffix
### Sword vs. Shield
Let's first think about two adjacent chunks.

After sorting each individually, they can be concatenated into a sorted array.

What does this imply? Quite obvious:

__$\max(Chunk_{left}) \leq \min(Chunk_{right})$__

Think of $\max(Chunk_{left})$ as a sword 🗡️

and $\min(Chunk_{right})$ as a shield 🛡.

For a shield to remain unbroken,

__its weakest point must be no weaker than the sharpest tip of any sword__.

### Scan Right Then Left
So for an array $nums$ of length $n$ (the problem calls it $arr$, but I prefer $nums$),

for every index $i$ satisfying $1 \leq i < n$, we check:

__Does $\max(nums[:i]) \leq \min(nums[i:])$ hold?__

If so, index $i$ is a __cut point__,

meaning the array can be split into two chunks at index $i$,

and sorting each chunk separately then concatenating will yield a sorted result.

This means we need to __first scan left__,

building a ```prefix_maxs``` array recording each $\max(nums[:i])$,

then scan back from the right, tracking $\min(nums[i:])$ with ```suffix_min```.

Whenever $\max(nums[:i]) \leq \min(nums[i:])$ holds,

increment ```max_chunks``` by 1. But remember:

### __```max_chunks``` starts at 1, not 0__
__Even a strictly decreasing $nums$ can count as one chunk__.

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCodePrefix}</CodeBlock>
  </TabItem>
  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCodePrefix}</CodeBlock>
  </TabItem>
</Tabs>

![Prefix Efficiency](0768_efficiency.png)
Time complexity $O(n)$, space complexity $O(n)$, with two passes through the array.

About a year and a half later, I thought of an alternative approach below...


## II. Early 2026: Monotonic Increasing Stack
### Eligibility to Lead a Chunk
Looking at the previous code, ```prefix_maxs``` is a continuous process of __expanding the current leader__.

Can you sense what kind of situation would make a leader

__ineligible to be the maximum of its chunk__?

Consider this scenario: $0 \leq j < k < l < n$

$nums[j] \leq nums[k]$ holds.

$\max(nums[:j + 1]) = nums[j]$ holds.

$\max(nums[:k + 1]) = nums[k]$ holds.

So $nums[j]$ leads $Chunk_j = nums[:j + 1]$,

and $nums[k]$ leads $Chunk_k = nums[j + 1:k + 1]$. All good so far.

### But Life Has Its "Buts"
Now comes $nums[l]$ satisfying $nums[l] < nums[j] \leq nums[k]$.

Since $k < l$, $nums[l]$ lies to the right of both $nums[j]$ and $nums[k]$.

With sharp instincts, we immediately smell a problem:

I. If $nums[l]$ is kept out of $Chunk_k$ (led by $nums[k]$),

then $nums[l]$ forms $Chunk_y$ with elements to its right.

After sorting, $Chunk_y$ meets $Chunk_j$ from the left —

__$nums[j]$ and $nums[l]$ end up out of order__.

II. Okay, so let $nums[l]$ join $Chunk_k$.

But after $Chunk_k$ is sorted and meets $Chunk_j$ from the left,

__$nums[j]$ and $nums[l]$ are still out of order__.

From both paths, we conclude directly:

$nums[l]$ and $nums[j]$ must be in the same chunk.

Separating them causes problems.

This is precisely why $nums[j]$ must step down and can no longer lead any chunk.

### Putting Monotonicity to Work
So we arrive at a conclusion: whenever the current $nums[i]$

__is smaller than ```prefix_maxs[-1]```__, we should:

(1). ```pop()``` to remove ```prefix_maxs[-1]```

(2). If ```prefix_maxs``` is not yet empty,

keep checking whether ```prefix_maxs[-1] > nums[i]```. If so, repeat step (2).

Otherwise, push the originally popped value back onto the right end of ```prefix_maxs```.

__Isn't this exactly the behavior of a monotonic increasing stack? 👌__

After traversal, count how many elements remain in the stack, say $s$.

__That means there are $s$ eligible chunk leaders. Return $s$.__

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCodeStack}</CodeBlock>
  </TabItem>
  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCodeStack}</CodeBlock>
  </TabItem>
</Tabs>

Both the stack and prefix approaches run in $O(n)$ time and $O(n)$ space, but the stack uses only a single pass.
