N = int(input())
cnt = 0
list_cnt = 0
ans_list = []
while(list_cnt <= 10 ** 12 + 1):
    str_cnt = str(cnt)
    if not ("1" in str_cnt or "3" in str_cnt or "5" in str_cnt or "7" in str_cnt or "9" in str_cnt):
        ans_list.append(cnt)
        list_cnt += 1
    cnt += 1

print(ans_list)
print(ans_list[N-1])


#TLE
