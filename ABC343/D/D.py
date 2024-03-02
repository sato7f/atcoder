N, T = list(map(int, input().split())) #N選手,Mクエリ
dc_dict = dict()
dc_set = {0}
for i in range(T):
    At, Bt = list(map(int, input().split()))
    if At - 1 not in dc_dict:
        dc_dict[At-1] = Bt
    else:
        dc_dict[At-1] += Bt
    dc_set.pop()
    dc_set.append(Bt)


    if(len(dc_dict) != N):
        print(len(set(dc_dict.values())) + 1)
    else:
        print(len(set(dc_dict.values())))
    

