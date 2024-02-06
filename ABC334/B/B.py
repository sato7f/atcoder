import math

A,M,L,R = list(map(int, input().split()))
L -= A
R -= A
#if R % M == 0 or L % M == 0 d = 1;
print(math.floor(R / M) - math.floor(L / M))