import sys

for readline in sys.stdin:
    a, b = readline.split()
    a = int(a)
    b = int(b)
    print(a + b)