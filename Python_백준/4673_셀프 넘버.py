def selfNumber(n):
    global othLst

    if n in othLst:
        return False
    else:
        return True

othLst =[]

for i in range(1, 10000):
        strI = str(i)
        ans = 0
        for j in strI:
            ans += int(j)
        result = i + ans

        if result not in othLst:
            othLst.append(result)

for k in range(1,10000):
    if selfNumber(k):
        print(k)