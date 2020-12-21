n = input()
tmp = n
cycleStr = ""
result = ""
cnt = 0

while True:
    cnt += 1
    cycleNum = 0
    for x in n:
        cycleNum += int(x)
    if cycleNum < 10:
        cycleStr = "0" + str(cycleNum)
    else:
        cycleStr = str(cycleNum)

    if int(n) < 10:
        n = int(n)
        result = str(n)[0] + cycleStr[1]
    else:
        result = n[1] + cycleStr[1]

    if int(tmp) == int(result):
        print(cnt)
        break
    else:
        n = result