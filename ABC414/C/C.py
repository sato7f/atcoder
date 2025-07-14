import numpy as np

A = int(input())
N = int(input())

# kaibun_10 = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "11", "22", "33", "44", "55", "66", "77", "88", "99"]
kaibun_10 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
for i in range(2, 13):
# for i in range(3, 5):
    # print("i:", i)

    # half = (i + 2 - 1) // 2
    half = i // 2
    if half == 1:
        st = 1
        ed = 9
    else:
        st = 10 ** (half - 1) + 1
        ed = 10 ** (half) - 1
    # print(st, ed)

    # 偶数桁（左右対称のみ）
    if i % 2 == 0:
        ret_kb = ""
        for le in range(st, ed + 1):
            ret_kb = str(le) + str(le)[::-1]
            kaibun_10.append(int(ret_kb))
    # 奇数桁（真ん中＋左右対称）
    else:
        ret_kb = ""
        for le in range(st, ed + 1):
            for center in range(10):
                ret_kb = str(le) + str(center) + str(le)[::-1]
                kaibun_10.append(int(ret_kb))

# print(len(kaibun_10))
# print(kaibun_10[:100])
# exit(0)

su = 0
isok = []
for kb in kaibun_10:
    if int(kb) > N:
        break
    # base_change = str(int(kb, A))
    base_change = str(np.base_repr(kb, A))

    # if kb == 121:
    #     print("###", base_change)

    half = len(base_change)
    if base_change[0:half] == base_change[-half:][::-1]:
        su += int(kb)
        isok.append([kb, base_change])

print(su)
# print(isok[:100])
