---
title: "68. Text Justificator"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/queue/0068_hard/text_justificator.cpp?raw';
import PyCode from '@site/docs/queue/0068_hard/text_justificator.py?raw';


## [Text Justification](https://leetcode.com/problems/text-justification/description/)
A decent way to have experience with queues in LeetCode.

Given a list of words, we pack as many consecutive words as possible into each line,

but each line must be padded to exactly ```maxWidth``` characters,

and __spaces must be placed between words__ — how many depends on situations.


## First In First Out
Set up a queue to hold words which are __currently being assembled into a line__.

Since at least one space is needed between any two adjacent words,

minimum line length formed by these queued words is:

__$L = \text{len}(\text{queue}) - 1 + \Sigma_i \; \text{len}(\text{word}_i)$__

### Case 1: Length Exceeded
Once the current word $word_j$ causes

__$L + 1 + \text{len}(word_j) > \text{maxWidth}$__,

it's time for all currently queued words to form a line.

After forming a line, queue clears, and $word_j$ enters queue as next line's head word.

### Case 2: Space Remains
Otherwise, simply add $word_j$ to queue. The line doesn't need to form yet.


## Forming Line
As mentioned, number of spaces between adjacent words depends on situations.

The problem specifies two different spacing styles.

### 1. Left Justification
If the line being formed is the __last line__, it should be left-justified:

__exactly one space__ between adjacent words.

If total length still hasn't reached ```maxWidth``` after filling, pad spaces to the end of the line.

Note: if a non-last line contains only __one word__,

the spacing behavior __automatically becomes left-justified__.

### 2. Right Justification
Lines that are __not the last line and contain at least two words__ use right justification.

We have $\text{len}(\text{queue}) - 1$ gaps between words.

Total spaces to distribute: $S = \text{maxWidth} - \Sigma_i \; \text{len}(\text{word}_i)$

Each gap first receives: __$\lfloor S \div (\text{len}(\text{queue}) - 1) \rfloor$ spaces__

Remainder $M = S \bmod{(\text{len}(\text{queue}) - 1)}$ is usually greater than zero,

meaning $M$ extra spaces still need to be dealt.

Very simple: __take the leftmost $M$ gaps__ and give each one an extra space.

Grasp both justification styles, and this problem is all done.

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Queue Efficiency](0068_efficiency.png)
Both time and space complexity are $O(n)$.
