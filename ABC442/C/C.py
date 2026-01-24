import math

N, M = list(map(int, input().split()))

# 研究者番号をそのまま使用（indexにするために-1などはしない）
rigai_dic = [set([i]) for i in range(N+1)]

for i in range(M):
    Ai, Bi = list(map(int, input().split()))
    rigai_dic[Ai].add(Bi)
    rigai_dic[Bi].add(Ai)

# for i in range(N+1):
    # print(rigai_dic[i])

# 利害関係にない人たちの選び方
for i in range(1, N+1):
    N_C_DicSize = math.comb(N - len(rigai_dic[i]), 3)
    # print(N - len(rigai_dic[i]))
    print(N_C_DicSize, end=" ")
