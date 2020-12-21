#2309

lst = []
result = 0

for x in range(9):
    n = int(input())
    lst.append(n)
    result += n

lst = sorted(lst)

for y in range(len(lst)):
    for z in range(y + 1, len(lst)):
        if(lst[y] + lst[z] == result - 100):
            numY = lst[y]
            numZ = lst[z]

for i in lst:
    if(i != numY and i != numZ):
        print(i)