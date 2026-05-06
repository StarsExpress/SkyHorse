---
title: "2876. Visited Nodes"
---


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import CodeBlock from '@theme/CodeBlock';
import CppCode from './visited_nodes.cpp?raw';
import PyCode from './visited_nodes.py?raw';


### [Prerequisites](https://starsexpress.github.io/SkyHorse/docs/dfs/2360_hard/longest_cycle/)
__我平时不算正经的人 但这次我正经点说__

如果2360号这道识别环计算环长的题没掌握好

直接来2876号题 是有可能被『环』搞到没法生『还』


### [Count Visited Nodes in a Directed Graph](https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph/description/)
本难题是这样的 有个总共$n$个且点$n$条边的有向图 点标号是$0$到$n-1$

$n$条边信息都存在名叫```edges```的阵列

```edges[i]```是点$i$的出边指向的点标号

并且$edges[i] \neq i$ 说明没有自环点

又 __$0 \leq edges[i] \leq n - 1$__

因此显然每个点都有 __恰好一条出边__

现在任务是要我们为所有点计算 __从该点出发__

__一路上能访问多少不同的点__


### 每个点恰好一条出边......那么
相信大家已经能猜到 在这样的先决条件下

站在任何一个环$C$的点上启动DFS

只会在这个$C$兜圈子 毫无机会跳出$C$

__由于每个环成员都把唯一出边连给另一个环成员__

若环$C$有$k$个成员 显然从这$k$个成员点出发

__都仅能网内互打📲 访问$k$个自家人而已__

因此一旦识别♻️ 就能整团环的答案一网打尽☑️


### 非环点又是如何拿捏
显而易见 从任何非环点出发 都能访问自己

还有所有儿子能访问到的点

__因为老子把唯一的出边留给儿子__

__儿子唯一的出边留给孙子 没回来找老子🤪__


### 仅剩的难『关』：环的边界感
读到这边 我们自然从前面的解说

意识到 环点和非环点的计数逻辑有差

这时候就到了想个好法子轻松

__区分环点和非环点边界感的时候了__

我想到的一招是 由儿子结束DFS

往上一层回到老子的那一刻

__带一个整数回来给老子当提示__

这整数有两种情况：

I. -1：代表儿子不是环成员

于是老子肯定也不是环成员了

II. 一个正整数：代表儿子是环成员了

而这正整数是啥意思呢？

__环的起点的访问顺序$d[s]$__

事已至此 老子就能拿著自己的访问顺序

来得知自己是否也与儿子一样属环：

(1). 若老子的访问顺序 __$\geq d[s]$__

__那恭喜老子亦是环成员__ 同时老子要 __向上回报$d[s]$__

__让爷爷跟著判断自己是否也在环内__

(2). 若老子的访问顺序 __< $d[s]$__

那老子就 __不是环成员__ 咯

__是把守关内关外界线的山海关__

于是老子必须 __向上回报-1__

__告诉上层说自己不是环的一份子__


### 别忘了登出递归栈啊
就和在第2360号题一样 每个点结束DFS即将return时

__得把自己的访问顺序改成-2 象徵已确实出递归栈__

__判断环何时成形的逻辑 也与第2360号题一样__

![DFS Efficiency](2876_efficiency.png)

老样子 每个点每条边各经历一遍 时间复杂度O(V + E)

空间复杂度也和点与边数量呈线性关系 是O(V + E)

<Tabs>
  <TabItem value="cpp" label="C++" default>
    <CodeBlock language="cpp">{CppCode}</CodeBlock>
  </TabItem>

  <TabItem value="python" label="Python">
    <CodeBlock language="python">{PyCode}</CodeBlock>
  </TabItem>
</Tabs>
