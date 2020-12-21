#15649

# q = input()
# lst = []
#
# for x in range(1, 1 + int(q[0])):
#     lst.append(x)
#
# for y in lst:

n, m = map(int, input().split())

check = [False] * (n+1)
answer = [1] * m

def nAndM(index, n, m):
    if index == m:
        for i in range(m):
            print(answer[i], end=' ')
        print()
        return

    for x in range(1, n + 1):
        if check[x]:
            continue
        check[x] = True
        answer[index] = x
        nAndM(index + 1, n, m)
        check[x] = False

nAndM(0, n, m)