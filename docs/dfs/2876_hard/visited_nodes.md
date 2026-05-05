---
title: "2876. Visited Nodes"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './visited_nodes.cpp?raw';
import PyCode from './visited_nodes.py?raw';


### 什么样的图被深度优先搜索呢
只要是碰到图论题 __永远要非常注意待搜的图特徵__

有向/无向这是入门人都要晓得的细节

但有时待搜的图有更巧的特徵 比如像我们第2360号难题

给进来的有向图上 __所有节点都是至多只有一条出边的🔖__

这里就让我们的DFS能省去走岔路的时间


### 细节
当我们在递归的过程中 来到某个点$u$ 若$u$无出边

那自然就是个死胡同了 点$u$不会在环内

那么假如$u$有条指向点$v$的出边呢？目前点$v$有三种可能性：

I. 仍未被访问过🔴：那么我们就延著$(u, v)$继续递归下去

__毕竟$(u, v)$这条边是点$u$唯一的出边了__

不往下走我们就不知道$u$到底是不是环的成员

II. 正在递归栈上还没闪人🟡：__恭喜🎊这就是环成形的那瞬间__

$(u, v)$是这个新生的环 最后的那块拼图🧩

同时要赶紧记下来 点$v$是环的起点🏁

III. __进过且登出__ 递归栈了🟢：这时候哪怕$v$是某环$C$的成员

__$u$都确定不在环$C$内 具体分析就在这儿__

如果$v$是某环$C$的成员 那么显然有某个$C$中的点$w$享有连线$v$的出边

假设$(w, v)$是$C$的最后那块拼图 可知当初递归到了点$w$时

__看见的点$v$状态必然显示为II.『正在递归栈上还没闪人🟡』__

那若$(w, v)$并非$C$的最后那块拼图 则当初递归到了点$w$时

__看见的点$v$状态必然显示为I.『仍未被访问过🔴』__

然而递归到了点$u$时 __看见的点$v$状态却显示为III.『__进过且登出__ 递归栈了🟢』__

由此可知点$u$绝不会是上述的$w$ 因此点$u$绝不会环$C$成员

说到这边 我们已经能想到一套方案 来让点之间准确地沟通

__是否有个环刚成形 且尚未认列完全部成员__


<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>
