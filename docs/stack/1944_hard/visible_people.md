---
title: "1944. Visible People"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './visible_people.cpp?raw';
import PyCode from './visible_people.py?raw';


## [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/)
非常好玩的一道难题 我原本其实也被数学公式唬了


## 什么叫做看得见➡️右边的人
题目页有定义：总人数$n$的队列

假设有索引$i$和$j$ 其中$0 \leq i < j < n$

若第$i$和第$j$人 __他们中间全部的人都比这俩矮__

那么第$i$人才能看见第$j$人

因此题目写了一道数学公式作为判断依据：

__$min(heights[i], heights[j]) > max_{i < k < j}(heights[k])$__


## 咀嚼数学公式后能察觉
给定某索引$0 \leq i < j < n - 1$

__要是第$j + 1$人没有比第$j$人高__

__那么第$i$人和第$j + 1$人一定不满足前段数学公式__

因此第$i$人看不见第$j + 1$人

说到这 是不是就感觉到 __单调性又来啰😀__

结合由右向左遍历时 第$j + 1$人迭代到后

紧接著是第$j$人被迭代 第$i$人还要过阵子才轮到

自然能把第$j + 1$人从可能被左方人看的选项划掉

于是这选项不就是个后进先出的栈嘛


## 具体操作
### 弹栈神通🍿
每次第$j$人被迭代时 就把栈顶的人和第$j$人比较

__只要栈顶的人比第$j$人矮__ 就把栈顶的人弹出

同时要给 __第$j$人能向右看见的人数加一__

因为如此的弹法下 栈顶的人和第$j$人之间的所有人都比他们俩矮

栈弹到何时为止？弹到终于 __栈顶的人不比第$j$人矮__

### 小心细节㊙️️
弹到终于 __栈顶的人不比第$j$人矮__

进入了一个微妙的细节 要特别注意

(1). 首先 到这节骨眼 __栈顶人肯定能被第$j$人瞧见__

不管这位栈顶人是比第$j$人高 还是说一样高

第$j$人能向右看见的人数自然加一

毕竟开头说的数学公式能办到嘛

(2). 巧妙的来啦 栈顶人倘若比第$j$人高

那第$j$人左方的人 还有机会就看栈顶人

因为开头说的数学公式还有机会做到呀

__但是这个栈顶人要是和第$j$人一样高__

__那么第$j$人左方的所有人都看不见栈顶人__

因为开头说的数学公式做不到啦

得赶快弹走这位与第$j$人一样高的栈顶人

简而言之 这边的操作是

__两个分支情况都要给第$j$人向右的能见度加一__

__但只有在栈顶人和第$j$人同高时 才要弹栈顶__

千萬別弄混淆啦

搞定弹栈后 第$j$人再进栈顶

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Stack Efficiency](1944_efficiency.png)

时间复杂度：$O(n)$ 每个人进栈一遍 最多出栈一遍

空间复杂度：$O(n)$ 有可能大家都比右边人矮 都被锁在栈内
