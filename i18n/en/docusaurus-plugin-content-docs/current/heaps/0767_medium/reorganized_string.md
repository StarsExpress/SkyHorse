---
title: "767. Reorganized String"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/heaps/0767_medium/reorganized_string.cpp?raw';
import PyCode from '@site/docs/heaps/0767_medium/reorganized_string.py?raw';


## [Original Problem](https://leetcode.com/problems/reorganize-string/description/)
### Sanity Check Is Crucial
The approach isn't difficult. First, count occurrences of each character.

Then perform a __time-saving sanity check__:

$\text{frequency of some character} - \text{sum of frequencies of all other characters} \geq 2$

__If this happens, it's impossible__ — return "" since no valid rearrangement exists.

__How do we set threshold?__ Let $n$ be length of string.

When a character's frequency is $\frac{1 + n}{2}$, it's still within the limit.

But if it increases by $\frac{1}{2}$ to become $\frac{2 + n}{2}$, the difference becomes 2. A violation.

So sanity check should verify that no character's frequency __exceeds $\frac{1 + n}{2}$__.

### After Passing Sanity Check
Place all characters into a max heap, where each element is in the format __(remaining count, character)__.

As long as max heap has at least two elements:

pop top element $(Count_1, Char_1)$, then pop again to get $(Count_2, Char_2)$.

__Use exactly one of each character per round__:

append $Char_1$ and $Char_2$ to the unfinished ```reshapedString```,

then push $(Count_1 - 1, Char_1)$ back __only if $Count_1 - 1 > 0$__ —

__max heap is only for characters that haven't been exhausted yet__.

Same logic applies to $(Count_2 - 1, Char_2)$.


## When to Stop ✋🏻
When max heap has __0 or 1__ element remaining:

I. If empty, return ```reshapedString``` immediately.

II. If one element remains, it must be exactly 1: __because sanity check passed__.

Append its character to the end of ```reshapedString``` and return.

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Max Heap Efficiency](0767_efficiency.png)
Time complexity: $O(n \log k)$ where $n$ is string length and $k$ is number of distinct characters.

Space complexity: $O(n)$ where $n$ is string length.
