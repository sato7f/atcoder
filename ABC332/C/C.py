N, M = (int(x) for x in input().split())
S = input().split("0")
ans = 0
for s in S:
    ans = max(ans, len(s)-M, s.count("2"))
print(ans)