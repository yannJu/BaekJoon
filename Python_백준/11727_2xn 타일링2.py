#11727

# 1 3 5 11 21 43 .......
# i-1 번째에 2x1타일만 붙이는 경우 + i-2 번째에 2x2타일, 2x1타일을 붙이는 경우 (2가지)

n = int(input())
lst = [1] * (n + 1)

for x in range(1, n + 1):
    if x == 1:
        lst[x] = 1
    elif x == 2:
        lst[x] = 3
    else:
        lst[x] = lst[x - 1] + lst[x - 2] * 2

print(lst[-1] % 10007)