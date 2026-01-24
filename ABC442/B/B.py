Q = int(input())

status = [0, "stop"]
for i in range(Q):
    Ai = int(input())

    # 音量１上げる
    if Ai == 1:
        status = [status[0] + 1, status[1]]
    
    # 音量１下げる
    elif Ai == 2:
        status = [max(0, status[0] - 1), status[1]]
    
    # 再生/停止
    elif Ai == 3:
        if status[1] == "stop":
            status = [status[0], "play"]
        else:
            status = [status[0], "stop"]
    
    if status[0] >= 3 and status[1] == "play":
        print("Yes")
    else:
        print("No")

