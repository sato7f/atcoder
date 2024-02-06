N = int(input())
line = list(map(int, input().split()))
ind_dic = {}
for i in range(N):
    A = line[i]
    ind_dic[A] = i + 1

ans = [0 for i in range(N)]
ans[0] = ind_dic[-1]
print(ans[0])

for i in range(1, N):
    ans[i] = ind_dic[ans[i-1]]
    print(ans[i])
