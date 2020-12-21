import sys

cycle = map(int, sys.stdin.readline().rstrip())
list = list(map(int, sys.stdin.readline().rstrip().split()))

y = 0
m = 0

for i in list:
    y += (i // 30 + 1) * 10
    m += (i // 60 + 1) * 15

if(y == m): print("Y", "M", y)
else:
    if (y < m): print("Y", y)
    else: print("M", m)