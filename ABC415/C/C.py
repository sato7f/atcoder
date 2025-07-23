T = int(input())

for i in range(T):
    N = int(input())
    S = input()
    if S[-1] != 0:
        print("No")
        continue
    
    adj_list = []
    tb = []

    for j in range(N):
        if S[j] != 1:
            bit = format(j, '0{N}b')
            for k in range(N):
                if bit[k] != 1:
                    adj_list.append([])
    