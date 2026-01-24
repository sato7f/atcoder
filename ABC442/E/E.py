import math

# 極座標変換（傾きのみ）
def getFixedDegree(x, y):
    # r = math.sqrt(x**2+y**2)
    rad = math.atan2(y, x)
    degree = math.degrees(rad)

    if degree != 0:
        fix_degree = -1 * degree
    else:
        fix_degree = degree

    # print(fix_degree, degree)
    return fix_degree


N, Q = list(map(int, input().split()))

# 各モンスターごとの角度と座標
deg_x_y_id = []#[[0, 0, 0, 0] for i in range(N)]

# モンスターidでのモンスターの座標
points = {}

for i in range(N):
    Xi, Yi = list(map(int, input().split()))
    fix_deg = getFixedDegree(Xi, Yi)
    deg_x_y_id.append([fix_deg, Xi, Yi, i])

    points[i+1] = [Xi, Yi]

# 時計回りの角度でソート
deg_x_y_id.sort()

# print(deg_x_y_id)

# モンスターid , 部分和
num = dict()

# モンスター数の部分和計算
deg_x_y_id_sum = []
for i in range(N):
    if i == 0:
        deg_x_y_id_sum.append(deg_x_y_id[0] + [0])
        num[deg_x_y_id[i][3]] = 1
    else:
        deg_x_y_id_sum.append(deg_x_y_id[i] + [deg_x_y_id_sum[i - 1][4]])
        num[deg_x_y_id[i][3]] = deg_x_y_id_sum[i - 1][4] + 1
    


# deg_x_y_id_sum = {}
# for i in range(N):
#     if i == 0:
#         deg_x_y_id_sum[i] + [0])
#     else:
#         deg_x_y_id_sum.append(deg_x_y_id[i] + deg_x_y_id_sum[i - 1][4])


# 探索用
# deg_x_y_id_sum_x2 = deg_x_y_id_sum + deg_x_y_id_sum

print(num)

for i in range(Q):
    Ai, Bi = list(map(int, input().split()))
    # Bのが時計の奥にある
    if getFixedDegree(points[Ai][0], points[Ai][1]) < getFixedDegree(points[Bi][0], points[Bi][1]):
        print(num[Bi] - num[Ai])
    else:
        print(num[Ai] - num[Bi])
    
    
