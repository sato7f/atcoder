N = int(input())

print(N - 1, flush=True)

for i in range(N - 1):
    print(i + 1, end=" ")
    for j in range(i + 1):
        print(j + 1, end=" ")
    print("", flush=True)

oxlist = list(map(int, input().split()))

oxlist
