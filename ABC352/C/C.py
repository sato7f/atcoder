import itertools

N = int(input())
AB_list = []
for i in range(N):
    AB = list(map(int, input().split()))
    er = AB[1] - AB[0]
    AB_list.append([er] + AB)

AB_list = sorted(AB_list)
#print(AB_list)

sum_high = AB_list[-1][2] # 頭まで
for i in range(len(AB_list)-1):
    # print(sum_high)
    sum_high += AB_list[i][1]

print(sum_high)