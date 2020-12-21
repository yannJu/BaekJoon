#9461

# 1,1,1/2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37 ...
# 4번째 부터는 n-2 n-3더함
# 3번째까지는 기본적으로 있어야 함

n = int(input())

for _ in range(n):
    m = int(input())
    lst = [1] * m
    for i in range(m):
        if i < 3:
            pass
        else:
            lst[i] = lst[i - 2] + lst[i - 3]

    print(lst[-1])
