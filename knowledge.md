### ソート

- 昇順（小さい順）にソート  
`sort(all(v));`

- 降順（大きい順）にソート  
`sort(rall(v));`  
`rall(v) = v.rbegin(),v.rend()`  
ソート前にマイナスをかけて昇順にソートした後マイナスをかけて戻す

- pair の vector を first を基準にソート  
`sort(all(vp));`  
ソートしたい値は first に入れておこう！

### vector・string
- vector / string の特定の要素をカウントする  
`count(all(s), 'o')`

- string のスライス（string 文字列中の特定の範囲の文字列を抜き出す）  
`S.substr(first, end)`  
`end` は `S.end()` がデフォルト

- vector の最大値・最小値  
`*max_element(all(vec))`  
`*min_element(all(vec))`  


### 教訓
- 基本 long long 型を使う
    - 大きい値（$10^9$等）が条件にあった場合は特に気を付ける
    - INF でなく LINF

- 「l」（Lの小文字）は変数等に使用しない
    - 「l」「1」がフォントによっては見分けがつかず，デバッグの邪魔

### データ構造
- Union Find
- 優先度付きキュー
- セグラメント木

### アルゴリズム
- 尺取り法
- 二分探索 ←忘れがち
