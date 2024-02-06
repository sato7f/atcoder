import numpy as np

N = int(input())
cnt = 0
list_cnt = 0
ans_list = []
dict = ["0", "2", "4", "6", "8"]
cnt = 0

for i in range(pow(10, 12)):
    i_str = np.base_repr(8, base=5)
    ans_list.append(i_str)

print(i_str[0])


#TLE
