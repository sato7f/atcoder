N = int(input())
A = list(map(int, input().split()))

def mod8(a, b):
    return (a + b) % 10

sum_ans = 0
for i in range(N):
    for j in range(N):
        sum_ans += mod8(A[i], A[j])

print(sum_ans)
ans_kamo = sum(A)*(N*2)
print(ans_kamo, "?")

mainasu = 0
for i in range(N):
    mainasu += A[i] + A[i]

print((sum_ans - mainasu)/2)
print((mod8(sum_ans - mainasu, 0))/2)
