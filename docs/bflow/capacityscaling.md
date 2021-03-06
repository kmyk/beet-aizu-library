---
title: Minimum Cost Flow with Capacity Scaling
documentation_of: //bflow/capacityscaling.cpp
---

## `INF` の決め方
### 上限
`m * INF` がオーバーフローすると死ぬことがある
### 下限
`max - INF < min` を満たしていないと区別できない
### 結論
`max - min < INF < 2^w / m`

`w` はビット幅

## 解説記事
[Are there any learning materials of polynomial minimum cost flow algorithms?](https://codeforces.com/blog/entry/70740)

[ぼくの考えたさいきょうのフローライブラリ](http://misawa.github.io/others/flow/library_design.html)

[最小費用流の双対について](https://beet-aizu.hatenablog.com/entry/2019/10/20/150649)

[b-flow と双対](https://beet-aizu.hatenablog.com/entry/2020/09/24/152856)
