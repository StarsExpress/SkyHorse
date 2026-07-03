---
title: "987. Vertical Traversal"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './vertical_traversal.cpp?raw';
import PyCode from './vertical_traversal.py?raw';


## BFS还是非常重要滴
尽管使用频率与知名度 不能和与递归挂勾的DFS相比

可BFS在树和图论的层级遍历上 仍是有其精妙之处

__绝对不能让自己在俩搜索法只懂其中一边__

若对BFS不够熟的话 [先看下GeeksforGeeks这篇](https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/)

掌握了BFS基本原理后 再来做987号题


## [Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/)
虽然此题是Hard 可我还是会说

987号题是广度优先搜索的好暖身之处😉😏


## 二叉树的行列坐标
题目有说 任何一个父节点坐标若为$(x, y)$

它的左右子节点分别是$(x + 1, y - 1)$和$(x + 1, y + 1)$

非常浅显易懂 __父往左子是向左下滑__ 于是行数加1 列数减1

__父往右子是向右下滑__ 行数同样加1 __列数却是因此反过来要加1__

树根的坐标自然是$(0, 0)$ 毕竟树根站在 __中路__ 嘛


## 节点排序原则：先按列升序 同列按值升序
### 分各列追踪
此乃题目给我们的设定 又结合二叉树的特性

__每往下走一层 列必然向左扩张__

向右的延伸则要看情况而定 由此可见

能采取广度优先搜索这种层层下挖的风格 让我们解决本题

首先自然要准备个数组`columnsValues`

其由左到右存储着给二叉树由左到右每一列的专属数组

__专属数祖上 存放该列中升序后的全部节点值__

### 因此呢 关键仅在于
朝节点广度搜索的同时要记录

__目前`columnsValues`储存的最左列 是二叉树上的几号列？__

__还有储存的最右列 又是二叉树上的几号列？__

一旦BFS访问到的节点之列 比储存的最左列值`leftmostCol`还左

__`columnsValues`必须在最左边插入一个空数组__

空数组储存新的最左列之对应节点值

反过来 倘若是比储存的最右列值`rightmostCol`还右

__`columnsValues`必须在最右边插入一个空数组__

空数组储存新的最右列之对应节点值

### 能左能右 也是没谁咯
我们得知 `columnsValues`必须能兼具最左与最右的插入能力

__于是答案呼之欲出 双端队列便是我们`columnsValues`的根基__

### 左右延伸后的`columnsValues`索引定位
肯定会有人好奇 如果`columnsValues`能向左扩张

__这样要如何靠索引准确定位 某个树节点究竟该放哪儿？__

我让各位自己先停在这儿好好想明白 再往下读～～

### 远在天边 近在眼前
__没错 就是`leftmostCol`来做基准啰__

既然`leftmostCol`储存当前`columnsValues`的最左列值

__那么任何目前访问到的列值 减去`leftmostCol`__

不就是该列在`columnsValues`中的索引位置嘛🤓😎

### 搜集完全部的列与节点后
别忘记各列中节点值还要进行升序排序齁

内部排序好后 即可回传 毕竟外部早就排序完毕唷

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![BFS_Efficiency](0987_efficiency.png)
空间复杂度是$O(n)$ $n$是二叉树中的节点数

本就是BFS那先进先出的队列的空间特性

时间复杂度$O(nlogn)$ 因为有排序的关系
