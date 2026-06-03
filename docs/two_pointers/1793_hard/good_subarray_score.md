---
title: "1793. Good Subarray Score"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './good_subarray_score.cpp?raw';
import PyCode from './good_subarray_score.py?raw';


## [Maximum Score of a Good Subarray](https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/)
从本题对于好的子数组的左右边界描述：

左边界 $\leq k \leq$ 右边界

我们可看出 所有待搜查的子数组 都必须有$nums[k]$


## 既然老𝓚肯定得存在
何不就让我们把位$nums[k]$设为搜查中心？

开俩根指针：`leftidx`和`rightIdx`

一个负责从$k$递减扫向左尾 一个负责从$k$递增扫向右尾

每次的扫描 可分三种情形：

I. `leftidx`和`rightIdx`都没有越界

比较`nums[leftidx]`和`nums[rightIdx]`的大小

较大的那个会成为当前子数组的延伸对象 就是新成员

选较大的的原因是 子数组的分数 = 子数组最小值 * 子数组长度

选较大者自然能尽量维持子数组的最小值 或者降低下滑量

II. `leftidx`越界 只能请`rightIdx`递增

III. `rightIdx`越界 只能请`leftidx`递减

如此的移动 遍能覆盖全部带有$nums[k]$的子数组啰

仅需于每次移动后 计算当前子数组的分数

和历史最高分数`maxScore`比较 做出必要的更新即可

![Two Pointers_Efficiency](1793_efficiency.png)

时间复杂度是$O(n)$ 我们所有数字都被访问了刚好一次

空间复杂度能压到$O(1)$ 因为我们只需要两根指针

当前子数组最小值 子数组分数 还有历史最高分数 五变量搞定

题外话 如上的贪心双指针解方 后来被我发起pull request

[合并到LeetCode Wiki 把空间复杂度从$O(n)$调到$O(1)$](https://github.com/doocs/leetcode/pull/5215)

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>
