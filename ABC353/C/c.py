N = int(input())
A = list(map(int, input().split()))

def mod8(a, b):
    return (a + b) % 10**8

mainasu = 0
for i in range(N):
    mainasu += mod8(A[i], A[i])

all_sum = 0
for i in A:
    all_sum += 

print(sum_ans)
