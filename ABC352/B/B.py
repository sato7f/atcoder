S = input()
T = input()

#ans_index = []
S_list = []
T_list = []
for s in S:
    S_list.append(s)
for t in T:
    T_list.append(t)

index_cnt = 0

for i in range(len(T_list)):
    if T_list[i] == S_list[index_cnt]:
        print(i + 1, end=" ")
        # S_list[S_list.index(T_list[i])] = " "
        S_list[index_cnt] = " "
        index_cnt += 1
    T_list[i] = " "

