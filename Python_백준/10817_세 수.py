num = input()
lst = num.split()

max = 0
secondMax = 0
min = 100000000000000
secondMin = 100000000000000

for i in lst:
    i = int(i)
    if (i > secondMax):
        if (i > max):
            secondMax = max
            max = i
        else:
            secondMax = i

for i in lst:
    i = int(i)
    if (i < secondMin):
        if (i < min):
            secondMin = min
            min = i
        else:
            secondMin = i

print(secondMax)
print(secondMin)