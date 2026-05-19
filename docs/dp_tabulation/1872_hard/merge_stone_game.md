---
title: "1872. Merge Stone Game"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './merge_stone_game.cpp?raw';
import PyCode from './merge_stone_game.py?raw';


## [Stone Game VIII](https://leetcode.com/problems/stone-game-viii/description/)
1872这道难题 是我印象特别深刻的一个DP问题

LeetCode经典的Alice & Bob玩游戏

基于个人习惯 我都叫他们 __春娇与志明__

![春娇与志明.jpeg](love_in_the_buff.jpeg)


## 永远的春娇先攻
老惯例了 LeetCode春娇走第一步 __女士优先精神__

那我们就把自己 __带入春娇的角色__ 来看倘若我们是她

会如何开第一手呢？最简单的第一手 肯定就是

春娇一条龙把全部石子都合并成一颗

让游戏来到仅剩一颗石子自动终结的局面

春娇因此赚到$\text{sum}(stones)$这么多分数

志明因为没得上场 自然是得0分

于是春娇的一条龙选择 让双方分差是$D_{n - 1} = \text{sum}(stones)$

$D$底下的索引说明这波合并包含了 __第$n - 1$颗石子__


## 但如果石头数量$\geq 3$呢？
### 还有其他选择可考虑
石头数量$\geq 3$ 说明春娇的第一手选择 可不止一条龙

__她也能选择露出部分石子 让志明上来合并取分__

那么我们就来看 若春娇有权让合并仅包含到第$n - 2$个石子

此时春娇赚来分数 __$\text{sum}(stones[:n - 1])$__

台面上剩下两个石头 靠右的面值$stones[n - 1]$

__靠左的是给春娇合并出来的 面值$\text{sum}(stones[:n - 1])$__

现在志明上场 也按规定不能Pass 必须合并俩石子 给自己赚到

$\text{sum}(stones[:n - 1]) + stones[n - 1] = \text{sum}(stones)$

双方分差因此是$D_{n - 2} = \text{sum}(stones[:n - 1]) - \text{sum}(stones)$

然后值得注意的是 __$D_{n - 2}$可藉由$D_{n - 1} = \text{sum}(stones)$__

__改写成$D_{n - 2} = \text{sum}(stones[:n - 1]) - D_{n - 1}$__

### 该换掉原本拿手里的选择吗？
于是现在有个 __二选一场景：$D_{n - 2}$ vs. $D_{n - 1}$__

(1). 如果$D_{n - 2} > D_{n - 1}$ 春娇会放弃一条龙方案

改为合并只包含到第$n - 2$颗石子 留下第$n - 1$颗

又前面推导过 $D_{n - 2} = \text{sum}(stones[:n - 1]) - D_{n - 1}$

$D_{n - 2} > D_{n - 1}$等价$\text{sum}(stones[:n - 1]) - D_{n - 1} > D_{n - 1}$

翻译成白话文就是： 『对手呀～$D_{n - 1}$我送给你啰

这是因为我有更强悍的选项$D_{n - 2}$ __厉害到哪怕你的$D_{n - 1}$对冲__

__我的净分差还大于直接手拿$D_{n - 1}$的分差耶__』

(2). 反过来 若$D_{n - 2} \leq D_{n - 1}$ 春娇继续一条龙方案

同时我们还得回到推导过的那条数学式

$D_{n - 2} = \text{sum}(stones[:n - 1]) - D_{n - 1}$ 可知

$D_{n - 2} \leq D_{n - 1}$等价$\text{sum}(stones[:n - 1]) - D_{n - 1} \leq D_{n - 1}$

我们一样也有白话文来翻译：『合并只包含到第$n - 2$号石子

固然我因此赚了$\text{sum}(stones[:n - 1])$分 但对手也能赚$D_{n - 1}$分

对冲后我净胜人家$\text{sum}(stones[:n - 1]) - D_{n - 1}$分

__比数值大小发现 那还不如我直接把第$n - 1$颗石头也合并进来__

__领$D_{n - 1}$做净胜分 这样子更好__』

__也由于这番解读 我们必须给$D_{n - 2}$赋予$D_{n - 1}$的值__

反映一个关键现象：__只剩第$n - 2$和$n - 1$号石子尚未被合并时__

基于前面算的分差大小 __确定了一口气连第$n - 1$号石子一起合并__

__是比只合并到第$n - 2$号石子更棒的方案__

__于是淘汰掉只合并到第$n - 2$号石子的选项__

被淘汰此乃题目的特地规定啊 __有说每个玩家都是选择最优策略__

### 从此往下递推状态转移方程
同样的逻辑 要是有合并只到第$n - 3$颗石头的选项

那我们有$D_{n - 3} = \text{sum}(stones[:n - 2]) - D_{n - 2}$

于是进入了$D_{n - 3}$和$D_{n - 2}$的二选一场景

是不是从此识别状态转移方程了呢？没错 大家肯定猜到了

__$D_{i} = max(D_{i + 1}, \; \text{sum}(stones[:i + 1]) - D_{i + 1})$__

其中索引范围是$1 \leq i \leq n - 2$ 为何长这样：

(1). __索引范围没有零__

__是因为题目规定每次都得合并起码两颗石头__

(2). 索引范围又为何没包含$n - 1$呢？因为我们的

__Base Case恰恰是开局把全部石头合并 游戏结束__

一口气把第$n - 1$个石子都照顾进来

__于是Base Case的数字$D_{n - 1} = \text{sum}(stones)$__

### 状态转移方程的解说
我当时注意到有个相当能体现本质的描绘：

已知当台面上仅剩第$i + 1, ..., n - 1$颗石子们时

此刻登场的玩家 到头来能赚$D_{i + 1}$这么多净胜分

而我只合并到第$i$颗石子 赚来的$\text{sum}(stones[:i + 1])$分

有办法被$D_{i + 1}$对冲后 还比$D_{i + 1}$大吗？

I. 有做到的话 __那我愿意下一盘更大的棋__

__宁愿牺牲掉已知的好康 只为了即将登场的更大好康__

II. 没做到的话 __这$D_{i + 1}$好康不能被对手抢了__

__还不赶快纳入口袋 给自己灌净胜分__

于是大家也察觉到了 本题的状态转移比较特殊一些

__是由较大的索引转往较小的索引__

因此做状态转移时 __建议从较大索引往较小索引遍历__

[省得要搞额外DFS和cache来 导致$O(n)$空间复杂度](https://algo.monster/liteproblems/1872)

另外 状态转移方程告诉我们

__每一个索引的状态 全只看上一个索引的脸色__

[于是无需像这样开数组花$O(n)$空间复杂度记状态](https://walkccc.me/LeetCode/problems/1872/)

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

直接开叫做`max_score_diff`的变量记载$D_i$即可

![Bottom Up Efficiency](1872_efficiency.png)

如此时间复杂度$O(n)$ 空间复杂度$O(1)$


## 延伸问题
I. 上述的代码 该如何做增添

打印出春娇和志明 __全部的『Scoring Plays』__？

Scoring Play的定义就是上台的玩家合并了某些石子赚到分数

II. __为了让游戏更加精采 我们的目标是最大化Scoring Plays数量__

想达成这个目标 如何设计输入数组`stones`？
