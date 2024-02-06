S = input()
ans = ""
for i in S:
    ans += i
    if i == ".":
        ans = ""
print(ans)