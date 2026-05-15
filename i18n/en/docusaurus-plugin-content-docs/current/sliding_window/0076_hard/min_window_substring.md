---
title: "76. Min Window Substring"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/sliding_window/0076_hard/min_window_substring.cpp?raw';
import PyCode from '@site/docs/sliding_window/0076_hard/min_window_substring.py?raw';


## Sliding Window Problems: Common Pattern
Once ```left_idx``` and ```right_idx``` satisfy some condition,

compute window length ```right_idx``` + 1 - ```left_idx```,

compare it with historical max or min window length, and update records.

Sometimes we also need to store window's starting index.

Then move ```left_idx``` to the right until condition is no longer met, or ```left_idx``` > ```right_idx```.


## [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/)
Let's use problem 76 as a demonstration.

We're given two strings ```source_str``` and ```target_str```

(the problem uses ```s``` and ```t```, but ```source_str``` and ```target_str``` are more readable).

We have to find the shortest substring in ```source_str```

__that contains all characters in ```target_str```, including duplicates__.

If no such substring exists, return an empty string.


## Our Old Friend Hash Map 🔢
First, count occurrences of each character in ```target_str```,

since these are the characters we must __fully cover, including duplicates__.

Call this map ```tgt_chars_counts```.

Also prepare two variables upfront:

1. ```min_len```: the shortest window length found so far, initialized to ```len(source_str) + 1``` __to imply no valid substring found yet__
2. ```min_left_idx```: the ```left_idx``` of the shortest window found, initialized to -1


## Like Insurance: Over-coverage Is Fine, But Not Under
### I. ```right_idx``` Always Moves Right
Create an integer variable ```unique_tgt_chars_coverage```

to track how many __unique__ characters in ```target_str``` the current window __fully covers__.

Each time we move ```right_idx``` to the right,

let ```char``` = ```source_str[right_idx]```.

First check if ```char``` is a key in ```tgt_chars_counts```.

__Only if it is, ```char``` is something we need to cover.__

If so, decrement ```tgt_chars_counts[char]``` by 1,

__symbolizing that we've bought one more unit of insurance for ```char```__.

The moment ```tgt_chars_counts[char]``` drops to 0,

__it means full coverage of ```char``` has been achieved__,

so increment ```unique_tgt_chars_coverage``` at that point.

One key point: even after ```char``` is fully covered,

__every future occurrence of ```char``` should still decrement ```tgt_chars_counts[char]```__.

__Going negative is fine__, as it just means __over-coverage__, which is allowed.

Just don't increment ```unique_tgt_chars_coverage``` more than once 😏

__Only when ```tgt_chars_counts[char]``` drops to exactly 0 should our coverage count increase.__

### II. When Can ```left_idx``` Move Right?
Once ```unique_tgt_chars_coverage``` matches ```len(tgt_chars_counts)```,

our current window fully covers all characters in ```target_str```.

Quickly compute current window length: ```window_len``` = ```right_idx``` + 1 - ```left_idx```.

Compare with ```min_len```. If it's a new record,

__also update ```min_window_left_idx``` with ```left_idx```__,

__since we'll eventually need it to slice ```source_str``` for the answer__.

After recording and updating, move ```left_idx``` to the right.

A character falls out of window — let's call it ```removed_char``` = ```source_str[left_idx]```.

Again, check if ```removed_char``` is a key in ```tgt_chars_counts```.

__Only if it is, ```removed_char``` is something we were covering.__

If so, increment ```tgt_chars_counts[removed_char]``` by 1,

__symbolizing that we've canceled one unit of insurance for ```removed_char```__.

The moment ```tgt_chars_counts[removed_char]``` gets greater than 0,

__```removed_char```, which was fully covered, is now exposed__.

At that point, decrement ```unique_tgt_chars_coverage``` by 1.

Just like before, even if ```removed_char``` is already exposed,

__each additional loss of ```removed_char``` should still increment ```tgt_chars_counts[removed_char]```__,

since it means gap is growing and will need to be filled later.

Just don't decrement ```unique_tgt_chars_coverage``` more than once 😏

__Only when it goes from 0 to positive should our coverage count decrease.__

After a full scan, check if ```min_len``` equals ```len(source_str) + 1```.

If so, no valid substring was found so we return "".

Otherwise, return ```source_str[min_window_left_idx: min_window_left_idx + min_len]```.

<Tabs>
  <TabItem value="cpp" label="C++">
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python" default>
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>

![Sliding Window_Coverage Efficiency](0076_efficiency.png)
Time complexity: $O(|\text{source\_str}| + |\text{target\_str}|)$

Space complexity: $O(|\text{target\_str}|)$
