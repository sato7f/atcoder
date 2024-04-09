import sys
W, B = list(map(int, input().split()))
print(W, B)

S = "wbwbwwbwbwbwwbw"
SS = ""
while(len(SS) < 300):
    SS += S
# print(S)

for i in range(len(SS)):
    checkS = SS[i : i + B + W]
    if(checkS.count("w") == W and checkS.count("b") == B):
        print("Yes")
        sys.exit(0)

print("No")


