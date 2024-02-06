N = int(input())
dic_2 = [int("1"*n) for n in range(1, 11)]
#N_2 = bin(N)[2:]
ans = [0, 0, 0]
v = 0

for i in range(N-1):
    #for dig in range(3):
    if ans[0] == ans[1] == ans[2]:
        ans = [ans[0] + 1, 0, 0]
    else:
        idx = ans.index(min(ans))
        ans[idx] += 1
    print(ans)
print(dic_2)
for i in range(3):
    v += dic_2[ans[i]]
print(v)