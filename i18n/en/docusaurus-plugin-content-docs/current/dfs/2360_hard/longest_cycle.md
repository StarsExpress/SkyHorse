---
title: "2360. Longest Cycle"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/dfs/2360_hard/longest_cycle.cpp?raw';
import PyCode from '@site/docs/dfs/2360_hard/longest_cycle.py?raw';


## [Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph/description/)
A classic cycle detection problem — DFS is the most intuitive way.

One advantage of this problem is that these $n$ nodes are labeled $0$ to $n - 1$ as non-negative integers,

so a plain ```vector<int>``` works perfectly to track visit orders.

Using ```unordered_map<int, int>``` would be much slower......🐢


## When Does a Cycle Form? Think About It First
As we recursively traverse this directed graph and arrive at node $u$,

if $u$ has no outgoing edge, it's a dead end — node $u$ is no part of any cycle.

Now suppose $u$ has an outgoing edge toward node $v$. Node $v$ has three possible states:

I. Not yet visited 🔴

II. Currently on the recursion stack 🟡

III. Previously visited and already off the stack 🟢

Which state marks the moment a cycle is formed?

The answer is state II — currently on the recursion stack 🟡

__That's the moment to celebrate a newly formed cycle 🎊__

__$(u, v)$ is the last piece of puzzle for this new cycle $C$ 🧩__

Node $v$ is this cycle's start and node $u$ is the end 🏁. Length of cycle $C$ is __$d[u] + 1 - d[v]$__,

where $d[u]$ and $d[v]$ are the __visit orders of nodes $u$ and $v$__ respectively.

Since we are asked to find the longest cycle, __whenever a new cycle forms__,

we compare __$d[u] + 1 - d[v]$ against the current best__ and update if it's a new record.


## A Handy Tracking Trick
One small detail worth noting: __to quickly distinguish between states II and III above__,

I like to use different markers in the integer array ```visitedOrders```:

1. -1: node not yet visited 🔴
2. Positive integer: node is currently on the recursion stack 🟡 (which is the node's visit order)
3. -2: node has been visited and popped off the stack 🟢

![DFS_Efficiency](2360_efficiency.png)
Each node and each edge is visited exactly once. Time complexity is $O(V + E)$.

Space complexity is also $O(V + E)$.

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>


## Follow-up Problem
__[If problem 2360 is clear, come take on this one.](https://starsexpress.github.io/SkyHorse/docs/dfs/2876_hard/visited_nodes)__
