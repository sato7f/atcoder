N = int(input())
A = list(map(int, input().split()))

def mod8(a, b):
    return (a + b) % 10**8

sum_ans = 0
for i in range(1, N):
    for j in range(i+1, N+1):
        sum_ans += mod8(A[i-1], A[j-1])

print(sum_ans)
