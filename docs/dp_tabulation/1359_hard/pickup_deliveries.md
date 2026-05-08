---
title: "1359. Pickup Deliveries"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './pickup_deliveries.cpp?raw';
import PyCode from './pickup_deliveries.py?raw';


### [Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/)
又是一道非常适合Bottom Up的动态规划题

比[552号题](https://starsexpress.github.io/SkyHorse/docs/dp_tabulation/0552_hard/student_attendance)更简单些 起码我是这么觉得


### Base Case
当只有一个订单时 只有一种方案

先取(P)后送(D) 组合数便是1

长得这样子：$(P_1, D_1)$


### 观察往上爬的路线🧗
#### 1. $P_2$和$D_2$如何配置
__$P_i$永远要在$D_i$的左边 这是题目的要求__

因此我们先来留意$P_2$该摆哪儿

$(P_1, D_1)$这样的组合 有三个槽位(Slots)可安插$P_2$

放进$P_2$后 自然形成四个槽位 但这四个槽位

__就$P_2$的视角来说 是有变化滴__

I. 放在$P_1$左：__1 + 3__ 的格式

$+$号左 是指 __$P_2$左边__ 的槽位数

$+$号右 是指 __$P_2$右边__ 的槽位数

II. 放在$P_1$和$D_1$中：__2 + 2__ 的格式

III. 放在$D_1$右：__3 + 1__ 的格式

刚才提到$P_i$永远要在$D_i$的左边

因此$P_2$确定位置后 __$D_2$永远只能选__

__上述那些+号右边的槽位__

总共有$1 + 2 + 3 = 6$种可选

于是两份订单数量时 组合数便是$1 \times 6 = 6$

#### 2. 由此想像一下$P_j$和$D_j$ 若$2 \leq j$
$P_j$和$D_j$即将入队时 前面肯定有$j - 1$份订单

__形成了总长为$2j - 2$的序列__

$P_j$的插入位置于是有$2j - 1$个槽位

这些槽位由左到右 给予$D_j$的合法槽位数

__依序是$2j - 1, ..., 1$个这么多__

这不就是等差级数和$(2j - 1)j$嘛

恰好是在$P_j$和$D_j$的安排上

会让截至上一轮的组合数$C_{j - 1}$ __放大的倍率__

于是我们的状态转移方程有的是

$C_j = C_{j - 1} \times j(2j - 1) \; \forall \; j \in N; 2 \leq j$

好啦～～可直接进入手刻代码环节啰🧑🏻‍💻👩🏻‍💻

老话一句 数字可能来到天文级 记得要取模哦

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Bottom Up_Efficiency](1359_efficiency.png)
时间$O(n)$ 空间$O(1)$ __状态转移方程也要练习手写呀__
