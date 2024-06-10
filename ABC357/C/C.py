"""
def print33(cell="#"):
    for i in range(3):
        for j in range(3):
            if i == j:
                print(".", end="")
            else:
                print(cell, end="")
"""



#  print(729*729*6)

N = int(input())
li = [["#" for i in range(3**N)] for j in range(3**N)]

for n in range(N):
    # print("n=", n)
    for itr_i in range(len(li)):
        for itr_j in range(len(li[0])):
            i = itr_i % (3**(n+1))
            j = itr_j % (3**(n+1))
            # print(i, j)
            if (3**n <= i <= 2 * (3**n) - 1) and (3**n <= j <= 2 * (3**n) - 1):
            #if i == 1 and j == 1:
                # print(i, j)
                li[itr_i][itr_j] = "."

for i in range(len(li)):
    for j in range(len(li[0])):
        print(li[i][j], end="")
    print("")

