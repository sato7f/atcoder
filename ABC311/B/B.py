n, d = [int(s) for s in input().split()]
tmps = ["o" for _ in range(d)]

for i in range(n):
    nows = input()
    for j in range(d):
        if not (tmps[j] == "o" and nows[j] == "o"):
            tmps[j] = "x"

cnt = 0
max = 0
for i in range(len(tmps)):
    if tmps[i] == "o":
        cnt += 1
        if max < cnt:
            max = cnt
    elif tmps[i] == "x":
        cnt = 0
print(max)