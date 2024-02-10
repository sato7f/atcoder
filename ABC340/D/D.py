import heapq

def dijkstra(edges, num_node):
    """ 経路の表現
            [終点, 辺の値]
            A, B, C, D, ... → 0, 1, 2, ...とする """
    node = [float('inf')] * num_node    #スタート地点以外の値は∞で初期化
    node[0] = 0     #スタートは0で初期化

    node_name = []
    heapq.heappush(node_name, [0, 0])

    while len(node_name) > 0:
        #ヒープから取り出し
        _, min_point = heapq.heappop(node_name)
        
        #経路の要素を各変数に格納することで，視覚的に見やすくする
        for factor in edges[min_point]:
            goal = factor[0]   #終点
            cost  = factor[1]   #コスト

            #更新条件
            if node[min_point] + cost < node[goal]:
                node[goal] = node[min_point] + cost     #更新
                #ヒープに登録
                heapq.heappush(node_name, [node[min_point] + cost, goal])

    return node

if __name__ == '__main__':
    N = int(input())
    Edges = [[] for _ in range(N)]
    for i in range(N-1):
        A, B, X = list(map(int, input().split()))
        Edges[i].append([i + 1, A]) # [終点, 点の値]
        Edges[i].append([X - 1, B])
    
    # print(Edges)
    #今の目的地の数は7つ（0~6: A~G）
    node_num = N

    opt_node = dijkstra(Edges, node_num)

    print(opt_node[N-1])

    if(0):
        #以下は結果を整理するためのコード
        node_name = []
        for i in range(node_num):
            node_name.append(chr(ord('A') + i))    
        result = []
        for i in range(len(opt_node)):
            result.append(f"{node_name[i]} : {opt_node[i]}")
        print(f"'目的地:そこまでの最小コスト'\n\n{result}")
