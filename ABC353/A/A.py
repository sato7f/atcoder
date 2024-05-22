N = int(input())
H = list(map(int, input().split()))
for i in range(N):
    if H[0] < H[i]:
        print(i+1)
        exit()
print(-1)
