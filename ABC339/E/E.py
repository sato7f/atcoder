N, D = list(map(int, input().split()))
A = list(map(int, input().split()))
# print(N, D, Ai)

dp = [0] * N
for i in range(N):
    m = 0
    for j in range(i):
        if abs(A[i] - A[j]) <= D:
            m = max(m, dp[j])
    dp[i] = m + 1

print(dp)


