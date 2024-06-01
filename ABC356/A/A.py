N, L, R = list(map(int, input().split()))

li = [i + 1 for i in range(N)]

li_sli = [L + R- i for i in li[L-1:R]]
#print(li_sli)

cnt = 0
for i in range(N):
    if L-1 <= i and i <= R-1:
        print(li_sli[cnt], end=" ")
        cnt += 1
    else:
        print(li[i], end=" ")
    

