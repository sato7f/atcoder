N = int(input())
S = input()

for i in range(1, N):
    f = 1
    for l in range(N-i):

        #print(S[l], S[l+i])
        if S[l] == S[l+i]:
            print(l)
            f = 0
            break
    if f:
        print(l+1)