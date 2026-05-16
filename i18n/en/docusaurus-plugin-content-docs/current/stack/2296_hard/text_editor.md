---
title: "2296. Text Editor"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from '@site/docs/stack/2296_hard/text_editor.cpp?raw';
import PyCode from '@site/docs/stack/2296_hard/text_editor.py?raw';


## [Design a Text Editor](https://leetcode.com/problems/design-a-text-editor/description/)
Think of this __cursor as a dividing line__:

the __left side uses a LIFO stack__,

the __right side uses a deque that supports insertion and removal at front__.

This way, no matter where the cursor moves or how far it slides,
characters can be transferred between stack and deque with ease.


## Methods to Implement
### ```addText(string text)```
Push the entire ```text``` onto the left stack.

__Time complexity: $O(|\text{text}|)$__

### ```deleteText(int k)```
Delete ```min(k, len(stack))``` characters from the top of left stack.

Actual deletion count to return is ```min(k, len(stack))```.

__Time complexity: $O(k)$__

### ```cursorLeft(int k)```
Moving the cursor left by $k$ positions means our dividing line cuts off some left side characters,
__so characters near the top of left stack now are characters near the front of right deque__.

Pop ```min(k, len(stack))``` characters from the top of left stack one by one,
__and push each into the front of right deque__.

After these pops, go to the top of left stack
to slice substring consisting of ```min(10, len(stack))``` characters going leftward from there.

__Time complexity: $O(k)$__

### ```cursorRight(int k)```
Moving the cursor right by $k$ positions means our dividing line cuts off some right side characters,
__characters near the front of right deque now become characters near the top of left stack__.

Pop ```min(k, len(Deque))``` characters from the front of right deque one by one,
__and push each onto the top of left stack__.

After these pops, go to the top of left stack
to slice substring consisting of ```min(10, len(stack))``` characters going leftward from there.

__Time complexity: $O(k)$__

![Stack Deque_Efficiency](2296_efficiency.png)

Space complexity: $O(n)$, where $n$ is total number of characters on both sides of the cursor.

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>
