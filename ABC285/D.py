N = int(input())
S = [input().split() for _ in range(N)]
#print(S)

for i in range(N):
    for j in range(i, N):
        if S[i][-1] == S[j][0]:
            S[i].extend(S[j])
            S[j] = [None, None]

#print(S)

for i in range(N):
    if S[i][0] != None and S[i][0] == S[i][-1]:
        print("No")
        exit()
print("Yes")

