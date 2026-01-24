N, Q = list(map(int, input().split()))
A = list(map(int, input().split()))

# 部分和を計算しておく
S = [0 for i in range(N)]
S[0] = A[0]
for i in range(1, N):
    S[i] += S[i - 1] + A[i]

# print(A)
# print(S)

for i in range(Q):
    Qi = list(map(int, input().split()))
    
    # 交換クエリ
    if Qi[0] == 1:
        x = Qi[1] - 1
        A[x], A[x + 1] = A[x + 1], A[x]

        # 部分和の更新（O(1)でやる）
        S[x] += A[x] - A[x + 1]
        

    # 区間の合計クエリ（indexにそろえるために生の値を-1）
    elif Qi[0] == 2:
        L, R = Qi[1] - 1, Qi[2] - 1
        
        if L == 0:
            print(S[R])
        else:
            print(S[R] - S[L - 1])
    
    # print(A)
    # print(S)        