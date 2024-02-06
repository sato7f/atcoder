inpt = input()
s1 = inpt[0]
s2 = inpt[1]
inpt = input()
t1 = inpt[0]
t2 = inpt[1]
m = {"A":0, "B":1, "C":2, "D":3, "E":4}
s = abs(m[s1] - m[s2])
if s == 3:
    s = 2
elif s == 4:
    s = 1

t = abs(m[t1] - m[t2])
if t == 3:
    t = 2
elif t == 4:
    t = 1

if s == t:
    print("Yes")
else:
    print("No")
