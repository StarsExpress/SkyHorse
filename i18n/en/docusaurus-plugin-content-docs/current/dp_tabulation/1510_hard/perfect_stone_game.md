---
title: "1510. Perfect Stone Game"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './perfect_stone_game.cpp?raw';
import PyCode from './perfect_stone_game.py?raw';


## [Stone Game IV](https://leetcode.com/problems/stone-game-iv/description/)
This dynamic programming problem is a bit different from conventional DP tasks.

It requires some mathematical concepts.


## Odd vs. Even
From the problem description, we observe that:

if current player removes __a non-zero perfect square number of stones__,

__and leaves no stones remaining on the table, current player wins.__

Alice, as always, takes the first hand by default,

so if initial number of stones can be expressed as __a sum of an odd number of non-zero perfect squares__,

Alice definitely win. Otherwise, she loses.


## State Transition Equation
Based on observations above, we realize:

for any iterated remaining stone count $i$,

we just ask: __can this $i$ be expressed by a sum of an odd number of non-zero perfect squares?__

This answer, written as a state transition equation for $1 \leq i$ where $i \in \mathbb{N}$, is:

$$
squares\_counts[i] =
\begin{cases}
    1, & \text{if i is a perfect square itself} \\
    1, & \text{if } \exists \, perfect\_square \in [1, i) \text{ s.t. } squares\_counts[i - perfect\_square] = 0 \\ 
    0, & \text{otherwise} 
\end{cases}
$$

While the brace's 1st and 3rd conditions are quite apparent,

our core logic is the 2nd condition: $\mathit{squares\_counts}[i - \mathit{perfect\_square}] = 0$.

__This tells: $i - \mathit{perfect\_square}$ stones can only be expressed as a sum of an even number of non-zero perfect squares.__

__Added with current operation of removing $\mathit{perfect\_square}$ stones,__

__$i$ stones is for sure a sum of an odd number of non-zero perfect squares, fulfilling Alice's winning condition.__

With this clear insight, we have the state transition for our code 👌

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Bottom Up_Efficiency](1510_efficiency.png)
Time complexity is somewhat intriguing at $O(n\sqrt{n})$. $n$ represents initial number of stones.

For each stone state $i$, we must evaluate all non-zero perfect squares $\leq i$.

Space complexity is very straightforward at $O(n)$.
