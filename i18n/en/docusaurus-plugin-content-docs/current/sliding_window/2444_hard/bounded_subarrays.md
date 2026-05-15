---
title: "2444. Bounded Subarrays"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/sliding_window/2444_hard/bounded_subarrays.cpp?raw';
import PyCode from '@site/docs/sliding_window/2444_hard/bounded_subarrays.py?raw';


## [Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/)
Excellent problem to enhance sliding window technique.


## Since We Need Both minK and maxK to Be Bounded
Each time we move window's right end ```rightIdx```,

first check whether $minK \leq nums[rightIdx] \leq maxK$.

If not, $nums[rightIdx]$ falls outside valid range,

so __no valid subarray with ```rightIdx``` as the right end can exist__.

Directly reset window's left end ```leftIdx``` to ```rightIdx``` + 1,

and also reset both ```prevMinIdx``` and ```prevMaxIdx``` to -1,

since we don't yet know whether $nums[leftIdx:]$ contains elements equal to $minK$ or $maxK$.


## As Long as $nums[leftIdx: rightIdx + 1]$ Stay Fully In Bounds
We look within window for:

the most recent index $i$ where $nums[i] = minK$, and assign it to ```prevMinIdx```;

the most recent index $j$ where $nums[j] = maxK$, and assign it to ```prevMaxIdx```.

Once both ```prevMinIdx``` and ```prevMaxIdx``` are not -1,

__our window has just satisfied the problem's requirements__.

Valid subarrays within this window must satisfy three conditions:

(1). Right end exactly at ```rightIdx```

(2). Left end at least at ```leftIdx```, while not exceeding right end

(3). Left end at most at ```min(prevMinIdx, prevMaxIdx)```

(1) and (2) are intuitive. The key is where (3) comes from.

__If some index $k$ in the window satisfies ```min(prevMinIdx, prevMaxIdx)``` $< k$__,

__then $nums[k:rightIdx + 1]$ can't contain both $minK$ and $maxK$__.

Each bounded subarray is required to contain both $minK$ and $maxK$.

Therefore, number of valid subarrays in current window is:

__$C = $ ```min(prevMinIdx, prevMaxIdx) + 1 - leftIdx```__

Add $C$ to ```boundedSubarraysCount```, which will be returned at the end.

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Sliding Window Efficiency](2444_efficiency.png)
Time complexity $O(n)$ where $n$ is input array length.

Space is $O(1)$: just four pointers and ```boundedSubarraysCount``` to track total.
