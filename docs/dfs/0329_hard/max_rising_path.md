---
title: "329. Max Rising Path"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './max_rising_path.cpp?raw';
import PyCode from './max_rising_path.py?raw';


## [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/)
__必学的矩阵DFS题型 大概就是像329号这题__

要求找出最长的严格递增路径

限制是 站在每个点上企图延伸路径时

只能考虑东南西北任一方位 __不能开斜线模式__

当然 也不能跑离矩阵 因此边界管制是首要操作


## 轻松扫描全局答案
对于矩阵的每个元素`matrix[i][j]`

我们都要尝试由它为起点 寻找最长的递增路径长度

因此先开一个尺寸与`matrix`完全一致的`maxRisingPath`

初始化时 `maxRisingPath`所有元素都是-1 __象徵着尚未访问过__

然后对于每个`matrix[i][j]` 我们先看看四个 __潜在__ 邻居：

1. `matrix[i][j + 1]` 向东
2. `matrix[i + 1][j]` 向南
3. `matrix[i][j - 1]` 向西
4. `matrix[i - 1][j]` 向北

轮到邻居$x$做边界检查时 __一旦验证邻居$x$确实存在__

那就能继续看 __$x$的值是否比`matrix[i][j]`更大__

更大的话 再来查 __从$x$为起点的最长递增路径长度__

拿来加1便是 __从`matrix[i][j]`出发向$x$走时 能得到的最长递增路径长度__

因此如果邻居$x$在`maxRisingPath`显示-1

__说明$x$尚未被访问过 就得先拿DFS访问$x$__

一旦$x$的最长递增路径长度定下来 假设叫$k$

我们就采取 __$maxRisingPath[i][j] = max(maxRisingPath[i][j], 1 + k)$__

的方针更新`maxRisingPath[i][j]`

在更新好`maxRisingPath[i][j]`后 __别忘了和历史最大值比__

![Matrix_DFS Efficiency](0329_efficiency.png)
时间和空间复杂度都是$O(mn)$ 其中$m$和$n$分别是矩阵的行数和列数

第329题虽然官方标记Hard __但其实不难 甚至偏简单__ 非常适合练基础功

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>
