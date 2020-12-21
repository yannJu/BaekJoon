n = int(input())

lst = []
averageLst = []

for x in range(n):
    aL = list(map(int,input().split()))
    lst.append(aL)

for j in lst:
    num = j[0]
    result = 0
    for k in j[1:]:
        result += k
    averageLst.append(result/num)

for l in range(len(lst)):
    cnt = 0
    for m in lst[l][1:]:
        if m > averageLst[l]:
            cnt += 1
    print("{:.3f}%".format((cnt/(len(lst[l])-1)) * 100))

