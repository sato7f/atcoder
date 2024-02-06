S = input()[::-1]

q_num = 0
buf = ord("A")-1
for n in range(len(S)):
    q_num += (ord(S[n])-buf) * 26**n
print(q_num)