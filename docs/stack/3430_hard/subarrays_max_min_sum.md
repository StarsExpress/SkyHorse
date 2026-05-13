---
title: "3430. Subarrays Max Min Sum"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './subarrays_max_min_sum.cpp?raw';
import PyCode from './subarrays_max_min_sum.py?raw';


## [Maximum and Minimum Sums of at Most Size K Subarrays](https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subarrays/description/)
其实稍加思索会发现这题考的 不过就是两件事：

1. __有没有熟悉单调栈的基本特质__
2. __进一步把单调栈和其他数据结构合而为一__


## 如何让遍历逻辑更加便利？
由于题目给的任务是在输入的整数数组中 __把所有长度不超过自然数$k$的子数组 各自之最大值和最小值找出来__

接著对这群最大值与最小值求和回传一个整数 那么我们遍历原始数组的时候 最轻松的作法便是由

__每次迭代到的索引$i$作为子数组的结尾 看看全部符合如此条件的子数组__

各自的最大值和最小值是多少 这样自然能不多不少刚刚好掌握正确信息

当然本题有限制了子数组的 __长度不超过$k$__ 迭代时需要 __管制当前结尾索引$i$能搭配的起始索引$j$__

我个人面对扫描子数组之类风格题目时 向来习惯 __让迭代到的索引$i$作为子数组的结尾__

往前看 __该如何过滤起始索引$j$ 包含移动、计数、求和甚至是相乘__ 这样做的最大好处是

遍历的逻辑确实变得非常便利 不仅是为了 __便利遍历__ 这种谐音梗而已


## 边界管制
轮到索引$i$作为子数组结尾时 我们做的第一件事：

算出哪些起始索引$j$能 __合法地__ 搭配$i$ 组成长度不超过$k$的子数组

说的是那些$\leq i$且$\geq max(0, i - k + 1)$的索引$j$

一旦敲定好$j$的范围后 接下来的难点 需要篇幅解说


## 高效率的判别子数组最大值最小值
题目想要我们给的答案就是 __$S = \Sigma_{i = 0}^{n - 1} (MaxSum_i + MinSum_i)$：__

I. $MaxSum_i = \Sigma_{j = max(0, i - k + 1)}^i max(nums[j: i + 1])$

此乃索引$i$作结尾的所有合法子数组 各自最大值和

II. $MinSum_i = \Sigma_{j = max(0, i - k + 1)}^i min(nums[j: i + 1])$

此乃索引$i$作结尾的所有合法子数组 各自最小值和

我们如何高效率地算出这俩个总和呢

### 一、思路起点：预设情况
__先从预设情况开始 也就是$MaxSum_i$直接继承$MaxSum_{i - 1}$的值__ 再做两个调整：

__I. 永远会发生的__：加上$nums[i]$这个新来的数 作为最大值的贡献 毕竟现在多出一个仅有$nums[i]$的子数组了

__II. 特定条件才上演的__：如果$i - k + 1> 0$的话 要扣掉$nums[i - k]$所属的子数组的最大值贡献

__因为$nums[i - k: i]$这个长度k的子数组__ 在子数组结尾为$i - 1$时刚好合法

现如今必须给$nums[i]$入列 __就只能请最左端的$nums[i - k]$退休__ 这也是为何会要先做边界管制

上述这些操作都安排好了 尔后再去扫描看看有没有其他要调整的加减项

### 二、加减过程：逐步比大小检查交接
索引$i$作为结尾的全部合法子数组 必然都拥有$nums[i]$

因此如果$nums[i] \geq nums[i - 1]$的话 (1)

这些子数组的最大值就完全不可能是$nums[i - 1]$

至于我为何在不等式(1)中放入等号呢？咱们遍历是由左往右的

__如果相邻俩数一样的话 那选新来的更好啊～人家比较晚来 更加新鲜更能久留嘛😁__

由此可知 如此的情况下 $nums[i - 1]$它在索引$i - 1$为结尾的那些合法子数组中 做了那$l$遍的最大值

__这$l$遍要从此全额转交给$nums[i]$来当最大值了__ 因此会产生

__$(nums[i] - nums[i - 1]) * l$__ 这么多的净增量 给到$MaxSum_i$

$nums[i]$既然能通过比较让$nums[i - 1]$退位

那么$nums[i - 2], ...., nums[max(0, i - k + 1)]$也要和$nums[i]$比一比了

比到啥时停下来？__从i - 1往左比到第一个比$nums[i]$大的数$nums[j]$为止__

__再往左的数都比$nums[j]$更大 $nums[i]$赢不了 这不就是个单调递减栈吗？__

一路向左和那些不比自己大的数交接 把它们打出栈后 才轮到$nums[i]$入栈

$MaxSum_i$既然能如此靠单调递减栈实时追踪数额 那$MinSum_i$当然也能靠单调递增栈搞定了

__只不过它的转交判别是反过来的 $nums[i] \leq nums[i - 1]$才有交接仪式 (2)__

__和$MaxSum_i$的转交判别式(1) $nums[i] \geq nums[i - 1]$颠倒了不等号～～__

### 三、单调栈与队列的合体
前面有提到 每个迭代都要管制边界 把不在目前合法子数组范围内的子数组最大值/最小值剔除掉

__这个剔除是先进先出的过程 因此我们可把队列与单调栈合而为一 用Deque来同时FIFO和LIFO__

__每个栈上的成员都是一个三元组(Index, Number, Shares)__ 各有非常关键用途：

__I. Index__: 肯定要晓得担任最大值/最小值的数所在索引

边界管制才能知道它 __什么时候掉出当前子数组窗口而『强制退休』__

__II. Number__: 最大值/最小值的具体数值当然也要知道

因为双栈永远都在 __和新来的数比大小__

__III. Shares__: 在当前全部的合法子数组中

作为最大值(递减栈Max Stack)或最小值(递增栈Min Stack)的数 __其贡献份量__

__也就是前面转交解说中提到的$l$了__ 正是$l$帮忙校正$MaxSum_i$和$MinSum_i$的数额

好比有时发奖金 是在业绩结算前就先开出金额 __最后再根据业绩校正多退少补__

![Max Min Stacks Efficiency](3430_efficiency.png)
每个数都仅要入双栈各一次

出双栈次数加起来最多为2 时空复杂度自然均是$O(n)$

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>
