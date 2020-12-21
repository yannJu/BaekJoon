def oneNum(n):
    global ans

    if n < 100:
        ans += 1
        return ans
    else:
        strNum = str(n)
        lst = []
        for x in range(0, len(strNum) - 1):
             lst.append(int(strNum[x+1]) - int(strNum[x]))
        if lst.count(lst[0]) == len(lst):
            ans += 1
        return ans

num = int(input())
ans = 0
for n in range(1, num + 1):
    oneNum(n)
print(ans)