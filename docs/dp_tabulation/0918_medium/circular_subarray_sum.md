---
title: "918. Circular Subarray Sum"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './circular_subarray_sum.cpp?raw';
import PyCode from './circular_subarray_sum.py?raw';


### Quick Review
[Max Subarray Sum](https://leetcode.com/problems/maximum-subarray/)
👈这是非常经典的Bottom Up动态规划问题

可用Kadane算法 时间O(n) 空间O(1)

[Geeks for Geeks解說Kadane算法](https://www.geeksforgeeks.org/dsa/largest-sum-contiguous-subarray/)

☝️若还不熟悉Kadane算法 看这篇文章

拿捏好第53道题 那就来更奇葩的第918道题吧🤪


### [Circular Subarray Sum](https://leetcode.com/problems/maximum-sum-circular-subarray/description/)
第53号题只接受我们在长度$n$的数组$nums$中

找到两个索引$i$和$j$ 满足$0 \leq i \leq j < n$

最大化$sum(nums[i: j + 1])$

918号也和53号题一样接受上述这类子数组

但是918号题另外接受 __环形子数组__：

找到两个索引$i$和$j$ 满足$0 \leq i \leq j < n$

__最大化$sum(nums[:i] + nums[j: ])$__

简而言之便是在$nums$搞 __一段Prefix__ 和 __一段Suffix__

前提是 __不能有任一元素被重复使用__


### 天真的冤枉路🫨
有一说一 我当时拿下第53号题时

本来打算直接搞『阵列拼接模式』

尝试把$nums$拼接成$nums + nums$

好让53号题的精神原封不动套来

结果两个半月连续错了五遍🤣


### 逆向思考时间😌
又过了快三个月后 某一天我家门口

适逢施工🚧 有挖土机在挖土🪏

__看挖土机往地下掏的动作__ 我恍然大悟：

918号这题要用 __『挖除』__ 才行啦～～

对 就是从$nums$中找出 __最小且总和为负值__ 的那个子数组

__把这最负的子数组从$sum(nums)$扣掉__

来一招 __"Addition by subtraction"__ 排除毒瘤

就是最大化的环形子数组啦😁

本来53号题的Kadane算法是找出最大子数组

我们这儿要找出 __最小且总和负值的子数组__

加了负号这样子 逆向一波🫵


### 挖土机可不能随便挖的
好比施工时 要先确保不会挖到水管或电线

挖除最负子数组时 先要确保不会『一丝不挂』

什么意思？想想看 __万一$nums$全都不是正数__

__最负子数组不就是$sum(nums)$？__

这时从$sum(nums)$扣减 等于弄空的子数组

__但是子数组不能为空呀__

那该怎么办？ __简单追踪$max(nums)$呀__

只要$max(nums) \leq 0$ 意味所有元素都没正向作用

__此时选拖后腿幅度最小的那条腿 也就是$max(nums)$__

至于$max(nums) > 0$时 我们的答案可能是：
1. 如第53号题那样的最大子数组
2. 环形子数组：$sum(nums)$ - 最负子数组

因此本题要追踪的关键变量如下：
1. ```maxPosSum```：最大的正子数组和
2. ```minNegSum```：最小的负子数组和
3. ```arrayTotalSum```：$sum(nums)$
4. ```maxNum```：$max(nums)$

大致逻辑其实和第53号题还是一样

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![DP_Efficiency](0918_efficiency.png)
换个视角 就能时间O(n)和空间O(1)吃下一道怪题

不过有时要等老半天才终于换对视角😹
