import numpy as np
N = int(input())
itr = 3
ans = ""
for _ in range(N - 2):
    itr = int(np.base_repr(itr, 4).replace("0", "1"), base=4) + 1
    ans = np.base_repr(itr, 4).replace("0", "1")
    
    print(itr , ans)
    #print(np.base_repr(N, 4).replace("1", "1") + "3")