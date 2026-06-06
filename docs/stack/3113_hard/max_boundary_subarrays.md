---
title: "3113. Max Boundary Subarrays"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './max_boundary_subarrays.cpp?raw';
import PyCode from './max_boundary_subarrays.py?raw';


## [Find the Number of Subarrays Where Boundary Elements Are Maximum](https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/)
乍看超难 通过率仅~$34\%$

实则定睛看 非常容易抓住核心秒解

__题目名字太长起到的吓人作用👻__


## 子数组的最大值 同时出现在左右尾
此乃本题要求我们找出来的子数组特性

我们由此能立马意识到 遍历`nums`时的注意事项：

### 遍历到$nums[j]$时
任何满足$nums[i] < nums[j]$且$i < j$的$nums[i]$

与$j \leq k$的$nums[k]$围成的子数组$nums[i: k + 1]$

都没办法满足题目要求 __因为$nums[i] < nums[j]$__

__担任左尾的$nums[i]$确定不是此子数组最大值__ 没做到需求

因此 但凡$nums[i] < nums[j]$且$i < j$的$nums[i]$

__都可在遍历到$nums[j]$时被划掉 永久淘汰__

### 承上
把全部$nums[i] < nums[j]$且$i < j$的$nums[i]$都划掉了

剩下的$nums[i]$ 要么等同$nums[j]$ 要么更大

于是东西变简单了～

I. 如果都没有和$nums[j]$相等的$nums[i]$

那么$nums[j]$作为子数组右尾时

只有一个子数组满足题目要求 __就是$nums[j]$自己__

II. 倘若有和$nums[j]$相等的$nums[i]$

__我们仅需把$nums[i]$对应的计数$Count_{nums[i]}$加1__

加1后的$Count_{nums[i]}$ 也是$nums[j]$作为子数组右尾时

总共能吻合题目需求的可搭配左尾数

### 简述一下
__第I和第II点的共性：都会包含$nums[j]$自成子数组的情形__

__可是第II点还包含 早前和$nums[j]$相等的数作左尾的情形__


## 又双叒叕单调性
看到这边 大家已经意识到 这题的核心🫱单调性

靠严格递减单调栈做到前述的观察与策略

当遍历到$nums[j]$时 只要栈不为空

__且栈顶元素$nums[i] < nums[j]$ 就要弹栈顶__

弹到最后 有可能栈顶是个 __和$nums[j]$相等的$nums[i]$__

此时把$Count_{nums[i]}$加1就好

反之则是直接让$nums[j]$入栈 把$Count_{nums[j]}$设为1

__$nums[j]$做右尾 能搭的左尾数 必是栈顶元素绑定的计数__

需要注意的细节是 __计数是和元素绑定的__

__因此弹栈顶时 自然把$Count_{nums[i]}$给弹掉__

剩下的自然是 每次算好$Count_{nums[j]}$后

让$nums[j]$带著计数入栈

把$Count_{nums[j]}$加入要回传的`subarrays_count`中

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Stack_Efficiency](3113_efficiency.png)
时空复杂度就和典型的单调栈遍历题一样 双双$O(n)$

真的只要看穿遍历的淘汰机制 就能秒解啰～～


## 延伸问题
这道题目的答案`subarrays_count` 下限多少？上限多少？
