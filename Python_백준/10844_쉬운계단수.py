#10844
#
# (1 2 3 4 5 6 7 8 9)
# ->9
# (10 12 21
# 23 32
# 34 43
# 45 54
# 56 65
# 67 76
# 78 87
# 89 98)
# ->17
# (101 210 ,123 121 212, 321
# 234 232 323,432
# 345 343 434,543
# 456 454 545,654
# 567 565 656,765
# 678 676 767,876
# 789 787 878,987
# 898 989)
# -> 32

#양끝의 수보다 +- 1한 수를 붙이면 됨

n = int(input())
lst = [[0 for _ in range(10)] for _ in range(n + 1)]
cnt = 0

for x in range(1, n + 1):
    for y in range(0, 10):
        if x == 1:
            if y == 0:
                lst[x][y] = 0
            else:
                lst[x][y] = 1
        else:
            if y == 9:
                lst[x][y] = lst[x - 1][y - 1]
            elif y == 0:
                lst[x][y] = lst[x - 1][y + 1]
            else:
                lst[x][y] = lst[x - 1][y - 1] + lst[x - 1][y + 1]

for i in lst[-1]:
    cnt += i

print(cnt % 1000000000)