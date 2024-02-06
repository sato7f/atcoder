n = int(input())
s = input()
sset = set()
for i in range(len(s)):
    sset.add(s[i])
    if len(sset) == 3:
        print(i+1)
        break



