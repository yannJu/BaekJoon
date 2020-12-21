num = int(input())

resultLst = [0, 0, 1, 1]

if (num > 3):
    for i in range(4, num + 1):
        minLst = list()
        if (i % 3 == 0):
            minLst.append(resultLst[i//3] + 1)
        if (i % 2 == 0):
            minLst.append(resultLst[i//2] + 1)
        minLst.append(resultLst[i - 1] + 1)
        resultLst.append(min(minLst))
    print(resultLst[-1])
else:
    print(resultLst[num])