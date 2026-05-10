---
title: "295. Median Finder"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './median_finder.cpp?raw';
import PyCode from './median_finder.py?raw';


## [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/)
Heaps的重点应用 不仅是实时查最小值或最大值

__还能在数据流中实时盯著中位数__


## 数据流的中位数定义
- 长度$n$是奇数：排序后 __正中央那个数__ 比如$[1, 2, 3]$的中位数是$2$
- 长度$n$是偶数：排序后 __中间那俩数平均__ 比如$[1, 2, 3, 4]$的中位数是$(2 + 3) / 2 = 2.5$

定义好了后 我们就要看 不停加入新的数字时

如何随时知道排序后的中位数是谁


## 排序的言下之意
__一个排序好的序列 显然能拆成上下俩半身__

__下半身的『最大』肯定$\leq$上半身的『最小』__

因此我们能准备一个```min_heap``` 一个```max_heap```

```min_heap```维护上半身 ```max_heap```维护下半身

然后要遵守下方的条件：

I. __双方尺寸要嘛一样 要么```min_heap```比```max_heap```多一个元素__

若数据流目前有奇数个元素时 __中位数会在```min_heap```这儿__

也是此时```min_heap```比```max_heap```多一个元素

当然这是因为我习惯让中位数去上半身

选择放下半身其实也行 纯属个人偏好 有统一就好

II. __```max_heap```最大值$\leq$```min_heap```最小值__

没做到的话 就要不停双方交换 直到做到为止


## 新元素来时 先看Heaps尺寸
若两个堆尺寸一样 就把新元素丢到```min_heap```

若```min_heap```比```max_heap```多一个元素 新元素丢```max_heap```

__现在我们已经执行完毕前述的条件I__

接下来 我们要检查 __是否得矫正双堆__

也就是如果```max_heap```最大值$\gt$```min_heap```最小值

__那么```max_heap```最大值升级去```min_heap```__

__同理```min_heap```最小值降级去```max_heap```__

形成双方交易 交易到何时停止捏？

做到这句不等式即可结束矫正：

__```max_heap```最大值$\leq$```min_heap```最小值__

__此刻条件II也满足啦～～👌👌__


## 查找中位数 还是回到双堆尺寸
A. 若```min_heap```比```max_heap```多一个元素 

中位数就是```min_heap```最小值

B. 若两个堆尺寸一样 中位数是

```min_heap```最小值和```max_heap```最大值的平均数


## Python和C++预设不太一样欸⚠️
__Python的heapq预设min heap__

__C++的priority_queue预设max heap__

不是预设的那个半身 要记得negate数值

__就是给数值加上负号__

才能让预设min heap的也做得了max heap 反之亦然

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

LeetCode题目页Python区的 ```addNum```和```findMedian```

就是我的```add_num```和```find_median```

我习惯在C++才写🐫camel cases

Python我惯用🐍snake cases

![Two Heaps Efficiency](0295_efficiency.png)
加入新元素 需要$O(logn)$时间维护双堆 查找中位数仅需要$O(1)$时间

空间自然一直都是$O(n)$了

来到这 我强烈推荐[Tim Roughgarden教授的算法教程](https://youtu.be/mNYHDv7SbDI?si=QiBFwiNTJamQrebN)

除了Median Maintenance 还有不少非常有趣的Heaps应用

和最基础的堆原理解析
