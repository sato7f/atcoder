n = int(input())
a = [s for s in input().split()]
a = ["buf"] + a

logli = []
for i in range(1, n):
    log = []
    nowi = starti = i
    nexti = a[nowi]
    while(int(nexti) != int(starti) and len(log) < n):
        log.append(nowi)
        print(nowi, "→", nexti)
        tmp = nexti
        nowi = nexti
        nexti = a[int(nexti)]
    log.append(nowi)
    logli.append(log)

log = logli[0]
print(len(log))
print(log[0], end="")
for i in log[1:]:
    print("", i, end="")
    


        