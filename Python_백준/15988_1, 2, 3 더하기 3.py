#15988

n = int(input())

for _ in range(n):
    k = int(input())
    a = 1
    b = 2
    c = 4

    for x in range(k):
        if x > 2:
            tmp = c
            c += (a + b)
            a = b
            b = tmp

    print(c % 1000000009)