#11053

length = int(input())
num_Lst = list(map(int, input().split()))
lst = []

for x in num_Lst:
    if x not in lst:
        lst.append(x)

last = lst[0]
cnt = 1

for y in lst:
    if y > last:
        cnt += 1
        last = y

print(cnt)