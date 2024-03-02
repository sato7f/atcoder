N, T = list(map(int, input().split())) #N選手,Mクエリ
dc_dict_ninzu = {0:N} # key点の人は何人か
dc_dict_pt = dict() # key番の人が何点か
dc_set = {0}
for i in range(T):
    At, Bt = list(map(int, input().split()))

    if At - 1 not in dc_dict_pt:
        old_point = 0
        dc_dict_pt[At-1] = Bt
    else:
        old_point = dc_dict_pt[At-1]
        dc_dict_pt[At-1] += Bt

    dc_dict_ninzu[old_point] -= 1
    if(dc_dict_ninzu[old_point] == 0):
        dc_dict_ninzu.pop(old_point)

    # 新しく増えるポイントの人数
    if not (dc_dict_pt[At-1] in dc_dict_ninzu):
        dc_dict_ninzu[dc_dict_pt[At-1]] = 1
    else:
        dc_dict_ninzu[dc_dict_pt[At-1]] += 1



    if(len(dc_dict_ninzu) != N):
        print(len(dc_dict_ninzu) + 1)
    else:
        print(len(dc_dict_ninzu))
    
    print(dc_dict_ninzu.keys())
    

