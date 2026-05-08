---
title: "2412. Min Required Money"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './min_required_money.cpp?raw';
import PyCode from './min_required_money.py?raw';


### [Minimum Money Required Before Transactions](https://leetcode.com/problems/minimum-money-required-before-transactions/description/)
本题被标记成Hard的原因 我后来注意到了

是因为破题关键在于 __阅读测验__


### "Regardless of the order" of the transactions
题目中说我们得找出 __在任何交易执行顺序下__

都永远 __『兵来将挡 水来土掩』__ 的最小金额

也就是这个金额 __能确保不会在某笔交易完后__

导致现有的钱 __不够执行紧接著来的交易__

各位不妨先停下来想 什么情况特别容易目睹

__某笔交易结束后 手上剩馀的钱没法再去交易？__

肯定是......__经历了一连串的赔本交易__

把初始资金不停蚕食鲸吞光 一点一点消耗


### 绝对安全感的防弹衣🪖
由前一段叙述来看 至少必须能够撑得住

__所有赔钱交易的净亏损总额__

因此我们必须 __把全部$cashback_i < cost_i$的交易搜出来__

加总它们的亏损金额$L = \Sigma_i (cost_i - cashback_i)$

__但是还得再加上净亏交易中的最大cashback$x$__

Why?__如果从开头就连续操作全部亏损交易__

__且最后一笔亏损交易__ 的cashback恰恰是$x$

本金累积被扣幅度最凶的时刻 便是 __拿回$x$前的瞬间__


### 可是还有赚钱的交易呢
A. __若没任何赚钱的交易__ 那题目要的100%最小安全金额

肯定就是上面说的 __$L + x$__

B. 而要是有赚钱的交易 那就稍微要小心了

__毕竟赔本的交易了结后 现在还有赚钱交易得干__

赚钱交易的特性是每次结案 本金必不降

于是这时候我们只需要考虑一件事：

所有亏损交易消耗了我们后

__还有足够的钱来付任何赚钱交易的入场费嘛？__

__毕竟赚钱交易也不是天上掉馅饼__

__要先给出cost 才有cashback返还的__

看到这儿 大家大概有猜到我们亦需要

__$L + y$这个数字 $y$是所有赚钱交易中的最大cost__

这个数字的话中话是：

__如果运气最差 从开头就连续操作全部亏损交易__

__紧接著又撞见了入场费最贵的赚钱交易__

那么我们一开始就得携带$L + y$这么多钱

__才能守得云开见月明__

毕竟后面的赚钱交易入场费肯定不超过$y$

而赚钱交易的定义又是结案后 本金绝对不降

于是现在就是要比较 __$L + x$和$L + y$哪个更大__

__由更大的来作为我们最终的守护者__

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Greedy Efficiency](2412_efficiency.png)
有没有觉得 其实读懂了题意的话中话 就没有很难了

时间复杂度：$O(n)$ 空间复杂度：$O(1)$ 整题AC
