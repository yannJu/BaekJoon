#15650

n, m = map(int, input().split())

check = [False] * (n+1)
answer = [1] * m
lst = []
result = []

def nAndM(index, n, m):
    if index == m:
        s_lst = []
        for i in range(m):
            s_lst.append(answer[i])
        lst.append(s_lst)
        return

    for x in range(1, n + 1):
        if check[x]:
            continue
        check[x] = True
        answer[index] = x
        nAndM(index + 1, n, m)
        check[x] = False

nAndM(0, n, m)

for y in lst:
    if sorted(y) not in result:
        result.append(sorted(y))

for z in result:
    for l in z:
        print(l, end=" ")
    print()