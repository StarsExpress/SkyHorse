---
title: "1537. Max Score"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/two_pointers/1537_hard/max_score.cpp?raw';
import PyCode from '@site/docs/two_pointers/1537_hard/max_score.py?raw';


## [Get the Maximum Score](https://leetcode.com/problems/get-the-maximum-score/description/)
A great problem for training two pointers.

Key insight: whenever two sorted arrays share a common value,

that value becomes an __interchange__. For what?

We can __choose__ to switch our traversal path from one array to the other.

However, this switch is optional. __Only switch if doing so gives a better score__.


## 🗝️🔒 Two Pointers' Push & Pull
Each array has its own pointer 🪡.

As long as both `idxOne` and `idxTwo` don't go past the end of their respective arrays,

and their pointed values are not equal yet,

just keep incrementing the pointer having a smaller value,

__until its pointed value $\geq$ the other pointer's value__.

BTW: before incrementing, __that pointed value must add into its pointer's corresponding score__.


## 👩🏻‍❤️‍💋‍👨🏻 When the Couple Finally Agree
__Once both pointers point to the same value__,

directly compare `scoreOne` and `scoreTwo`,

and add `max(scoreOne, scoreTwo) + nums[scoreTwo]` to `maxScore`.

Why add `nums[scoreTwo]` as well? Remember:

the pointed value of a pointer is added to its score __right before incrementing__,

so our common value `nums[scoreTwo]` hasn't been counted yet.

Once `maxScore` absorbs `max(scoreOne, scoreTwo) + nums[scoreTwo]`,

both pointers advance by one step, while `scoreOne` and `scoreTwo` reset to 0.


## Someone Always Has to Clean Up
Just like the merge phase of that good old merge sort,

one array will always be finished first,

while the other still has unvisited values. The same happens here, too.

There must be exactly one pointer that hasn't scanned all values in its array,

so we need to keep incrementing it and adding values to its score.

Finally, add `max(scoreOne, scoreTwo)` into `maxScore`, and return `maxScore`.

Again, as asked: accumulated values can grow astronomically large,

we have to apply $10^9 + 7$ as modulo to control the size of `maxScore`.

![Two Pointers_Efficiency](1537_efficiency.png)

Our whole algorithm creates two pointers, three score variables, and one modulo constant.

6 variables needed in total, so space complexity is $O(1)$.

Time complexity is clearly $O(|\text{nums1}| + |\text{nums2}|)$. Each value is scanned only once.

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>
