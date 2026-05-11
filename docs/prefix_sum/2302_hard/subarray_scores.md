---
title: "2302. Subarray Scores"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './subarray_scores.cpp?raw';
import PyCode from './subarray_scores.py?raw';


## [Count Subarrays With Score Less Than K](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/)
刚开始看见这题时 我坦白告诉各位吧 我有感到担心

担心什么呢？担心这长度为$n$的 __纯正整数输入阵列__ 在$i < j < n$下 如果某个子数组$nums[i: j + 1]$

靠著$nums[j + 1]$这项 硬是让$\text{sum}(nums[i: j + 2]) * (j + 2 - i) < k$

那么我的由左往右遍历 可就得三不五时往回考虑各种子数组之和突然间暴跌的情况了

可是呢......

## 上述的担心真会在本题发生吗？🤔
输入的数组本身全是自然数 换言之固定左方索引$i$

若右方索引$j$引发$\text{sum}(nums[i: j + 1]) * (j + 1 - i) \ge k$

那么更右方的索引$l$ 同样会让$\text{sum}(nums[i: l + 1]) * (l + 1 - i) \ge k$成立

而且超出的程度还更严重 __因此前述的担忧叫做：杞人忧天🤣__


## 爽快！那就直接上吧
我们放心大胆地采取这道方针：__一旦发生了$\text{sum}(nums[i: j + 1]) * (j + 1 - i) \ge k$__

__就必须递增$i$ 直到$\text{sum}(nums[i: j + 1]) * (j + 1 - i) < k$终于成立 或者$i > j$为止__

这时候的$i$和$j$值 自然告诉我们 __右边界在$j$这索引的子数组中 有$j + 1 - i$这么多个子数组能满足$k$的约束条件__

对于每个$j$来讲 $i$最大可到达$j + 1$ 这时候$j + 1 - i = 0$ 翻译过来就是

第$j$索引为右边界的子数组中 没有任何一个能满足$k$的约束条件了

至于原因是为啥嘛......详见最下方的延伸问题区


## [随时要能联想自己写过的类似题解](https://starsexpress.github.io/SkyHorse/docs/queue/2398_hard/max_robots)
⬆️事实上本题的思路 就和第2398道难题是一样的 甚至还是简化版

__2398那题必须追窗口最大值 第2302题不用～～__

__因此能顺利节省了空间复杂度O(n)的单调递减队列__ 靠两个指针代表窗口左右端

再来一个叫做```subarraySum```的变量追踪$\text{sum}(nums[i: j + 1])$

![Prefix Sum Sliding Window_Efficiency](2302_efficiency.png)
__顺利简化到仅剩O(1)的空间复杂度而已～～时间复杂度仍是线性的O(n)__


## 插播：输入的阵列有正有负该如何
[Algo Monster](https://algo.monster/liteproblems/2302) 对第2302题使用的 __Binary Search__

__就是如果输入的数组有正有负时__ 能照样确保正确性的作法 代价是时间复杂度涨到O(nlogn) 空间复杂度涨到O(n)


## 审题非常重要 记得Bayes定理
如果只知道输入的数组全是整数 但不清楚正负情况

那我们只有$P(Y)$这样的先验概率做判读信息 得像Algo Monster开启比较麻烦的二分查找

但题目说的好清楚 只给自然数 __这便是似然$P(X | Y)$到手了__

__那还不赶快和先验概率相乘 一起逼近后验概率$P(Y | X)$ 做出更好的判读？__

__面试做Live Coding Test时 提前问清楚边界约束 就是必备的素养 给面试官也给自己方便__

我的第2302道难题就是这样 把时空复杂度

从Algo Monster的$O(nlogn)$与$O(n)$ 各自降到$O(n)$与$O(1)$

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>


## 延伸问题
当在扫描右边界索引为$j$的子数组时 看见左边界$i$递增成为了$j + 1$

我们能因此对$nums[j]$下什么样的结论呢
