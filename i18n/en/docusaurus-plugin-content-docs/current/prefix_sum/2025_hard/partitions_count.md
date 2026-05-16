---
title: "2025. Partitions Count"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/prefix_sum/2025_hard/partitions_count.cpp?raw';
import PyCode from '@site/docs/prefix_sum/2025_hard/partitions_count.py?raw';


## [Maximum Number of Ways to Partition an Array](https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/description/)
An extremely brain-burning problem. I got it wrong on my first eight attempts 😆

Back then, facing an obviously complex problem like problem 2025 with only around a 36% acceptance rate,

I was quite easy to fall into a shotgun approach.

I later learned to hit the brakes, observe calmly, then react.


## Default Max Partitions Count
The problem says we can choose to leave every element unchanged.

So first, look at original array of length $n$:

how many indices $i$ with $1 \leq i < n$ satisfy

__$\text{sum}(nums[:i]) = \text{sum}(nums[i:])$__?

Default value of max partitions count is:

$C = \Sigma_{i = 1}^{n - 1} \mathbf{1}(\text{sum}(nums[:i]) = \text{sum}(nums[i:]))$


## Hard Part: Changing One Element
The problem also allows us to pick __exactly one__ index $j$
__and replace $nums[j]$ with input $k$__.

This means we need to find which $j$ maximizes:

$C' = \max_{j} \Sigma_{i = 1}^{n - 1} \mathbf{1}(\text{sum}(nums'[:i]) = \text{sum}(nums'[i:]))$

__where $nums'$ differs from $nums$ only in that $nums'[j] = k$__.

The final answer is $\max(C, C')$.


## Find C'
### Concept of Prefix-Suffix Difference
First, prepare a hash map called ```rightDiffCounts```,
and a pivot index ```pivotIdx```. As defined by the problem,
__```pivotIdx``` must start from 1 and < $n$__.

As ```pivotIdx``` traverses from 1 to $n - 1$,

compute __prefix-suffix difference__ $D = \text{sum}(nums[:\text{pivotIdx}]) - \text{sum}(nums[\text{pivotIdx}:])$,

and record count of each $D$ in ```rightDiffCounts```.

What is this difference good for? Imagine:

if some index $l$ __less than ```pivotIdx```__ is selected,

__$nums[l]$ changes to $k$, and $nums[l] - k = D$__,

__then $\text{sum}(nums[:\text{pivotIdx}]) - \text{sum}(nums[\text{pivotIdx}:])$ becomes zero!__

```pivotIdx``` becomes a valid split point due to this change, and $C'$ increases by 1.

### The Symmetric Trap
one more thing to pay attention to:

when some index $l$ has $nums[l]$ changed to $k$,

__the valid split points it creates can be to the left or to the right of $l$__.

Using only ```rightDiffCounts``` (which tracks prefix-suffix differences for split points to the right of $l$)
is not enough.

We also need ```leftDiffCounts``` to manage differences for split points to the left of $l$.


## Traversal Logic for Final Counting
### Prefix Perspective
The traversal index $l$, where $0 \leq l < n$,

checks: after changing $nums[l]$ to $k$,

how many split points to the right of $l$ have a prefix-suffix difference of $nums[l] - k$?

The change to $nums[l]$ __affects the prefix sum from the perspective of split points to $l$'s right__.

Look up $nums[l] - k$ in ```rightDiffCounts``` for the count.

### Suffix Perspective
By symmetric reasoning, changing $nums[l]$ to $k$

__affects the suffix sum from the perspective of potential split points to $l$'s left__.

Count how many split points to the left of $l$ have a prefix-suffix difference of $k - nums[l]$.

Look up $k - nums[l]$ in ```leftDiffCounts``` for the count.

Number of perfect split points created by changing $nums[l]$ to $k$ is:

$C'_l$ = ```leftDiffCounts[k - nums[l]]``` + ```rightDiffCounts[nums[l] - k]```

Compare this with the current best $C$ and update if it's larger.

Note that since we're dealing with prefix and suffix perspectives,
__the queried differences differ by exactly a sign flip__.

### Update Both Hash Maps at Each Step
After visiting index $l$, compute $D_l = \text{sum}(nums[:l + 1]) - \text{sum}(nums[l + 1:])$.

Decrement $D_l$'s count in ```rightDiffCounts```.

Increment $D_l$'s count in ```leftDiffCounts```.

Because from the perspective of all indices larger than $l$,
__$l$ can only be a left split point, never a right one__.

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Prefix_Sum Efficiency](2025_efficiency.png)
Time complexity $O(n)$, space complexity $O(n)$.

Logic here is genuinely complex. Think it through several times before key insight clicks.
