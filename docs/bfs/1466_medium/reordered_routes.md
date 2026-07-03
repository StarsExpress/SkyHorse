---
title: "1466. Reordered Routes"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './reordered_routes.cpp?raw';
import PyCode from './reordered_routes.py?raw';


## [Reorder Routes to Make All Paths Lead to the City Zero](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/)
有点好玩的一道题 问的是在一张有向图上

如何翻转最少数量的边 使得所有点都能访问到第0号城市

已知条件是总共$n$座城市 仅有$n - 1$条边 __不会有环__


## 所有点都能访问第0号城市的图长啥样？
肯定是从第0号城市开始搜索时

__发现第0号城市连著的边 都是只入第0号城市的__

第0号城市不会有任何的出边 而接下来呢：

I. 若第0号城市的入边来自第$i$号城市

第$i$号城市的唯一出边 就是通往第0号城市

__因为前面有说此图是$n$个点和$n - 1$条边__

__因此第$0$号城市必无出边 其他城市皆拥有刚好一条出边__

II. 假设第$i$号城市身上的入边来自第$j$号城市

第$j$号城市的唯一出边 就是通往...没错～第$i$号城市

__理由和第I点这边说的完全相同逻辑__

III. 假设第$j$号城市身上的入边来自第$k$号城市 由此类推...


## I、II、III的递归关系
相信各位已经看出来 上述的I、II、III是一个递归关系

__不过这个递归关系在本题 未必要用DFS来做__

__BFS一样能轻松拿捏这边的递归关系__

且往下看就知道😁


## 先暂且忘却原图上边的方向
我们准备一个先进先出的队列

__队列起初仅有第0号城市 说明从第0号城市出发__

只要队列内还有东西 我们就：

把队首第$i$号城市从队列中取出 标记成已访问

然后看所有与第$i$号城市相连的边

只要这些边上对面的城市$j$还没被访问过

便将城市$j$加入队列中

同时检查一下第$i$号和第$j$号城市之间的边方向

__如果方向是从第$i$号城市指向第$j$号城市__

__体现这条边需要翻转才行 因此翻转计数加1__


<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![BFS_Efficiency](1466_efficiency.png)

每个点都被访问刚好一遍 都要追踪是否被访问过

因此时间和空间复杂度都是$O(n)$
