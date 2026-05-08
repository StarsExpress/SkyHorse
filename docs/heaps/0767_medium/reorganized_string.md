---
title: "767. Reorganized String"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './reorganized_string.cpp?raw';
import PyCode from './reorganized_string.py?raw';


### [Reorganize String](https://leetcode.com/problems/reorganize-string/description/)
思路不难 我们先把每个字符出现的次数统计出来

然后放在一个Max Heap里 这大堆中每个元素都是

__(剩馀次数, 字符)这样的格式 只要大堆还有起码两元素__

就先把堆顶元素$(Count_1, Char_1)$取出来

接著再取一遍堆顶元素$(Count_2, Char_2)$

__然后每次俩字符都各只用一个而已__

把$Char_1$和$Char_2$拼接到未完成的```reshapedString```上

再请$(Count_1 - 1, Char_1)$入堆 __前提是$Count_1 - 1 > 0$__

__毕竟大堆是拿来给还没耗光的字符啰__

$(Count_2 - 1, Char_2)$同理


### 何时收手呢✋🏻
就是大堆内只剩下 __零或一个__ 元素时：

I. 没剩元素肯定能立刻回传```reshapedString```

II. 要是还有剩 这时先看元素上的字符剩馀次数

__如果大于1那就没招了__ 只能回个""说明没法重组出相邻字符不重复的字串了

__等于1的话__ 那就把元素上这字符拼接到```reshapedString```末尾即可回传

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Max Heap Efficiency](0767_efficiency.png)
时间复杂度：$O(nlogk)$ $n$是字串长度 $k$是字符种类数

空间复杂度：$O(n)$ $n$是字串长度
