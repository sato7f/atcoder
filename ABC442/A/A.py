S = input()

cnt = 0
for i in range(len(S)):
    if S[i] == "i" or S[i] == "j":
        cnt += 1

print(cnt)