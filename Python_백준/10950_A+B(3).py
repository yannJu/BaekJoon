n = int(input())
lst = []

for i in range(n):
    a = input()
    b = a.split()
    lst.append(b)

for j in lst:
    result = 0
    for k in j:
        result += int(k)
    print(result, end="\n")
