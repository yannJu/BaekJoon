import sys

n = int(input())
lst = []

for i in range(n):
    a = sys.stdin.readline().replace("\n", "")
    b = a.split()
    lst.append(b)

for j in lst:
    result = 0
    for l in j:
        result += int(l)
    print(result, end = "\n")
