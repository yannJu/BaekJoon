import sys

a, b = map(int, sys.stdin.readline().rstrip().split())

def cal(a, b):
    y = 0
    while(True):
        if (a - y) % b == 0:
            return int((a - y)/ b), y
        else:
            y += 1

if (a > 0 and b > 0):
    print(a // b)
    print(a % b)
else:
    x, y = cal(a, b)
    print(x)
    print(y)