N, K = list(map(int, input().split()))
A = list(map(int, input().split()))

cnt = 1
while(True):
    aki = K
    for i in range(len(A)):
        if 0 <= (aki - A[i]):
            aki -= A[i]
            A[i] = 0
        else:
            break
    if A[-1] == 0:
        break
    # print(A, cnt)
    cnt += 1

print(cnt)