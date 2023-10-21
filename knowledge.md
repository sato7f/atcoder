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

### vその他
- vector / string の特定の要素をカウントする  
`count(all(s), 'o')`

- vector の最大値・最小値  
`*max_element(all(vec))`  
`*min_element(all(vec))`  
