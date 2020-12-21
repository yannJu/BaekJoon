#2748

n = int(input())
lst = [0] * (n + 1)

for x in range(n + 1):
    if x == 0:
        lst[x] = 0
    elif x == 1:
        lst[x] = 1
    else:
        lst[x] = lst[x - 2] + lst[x - 1]

print(lst[-1])