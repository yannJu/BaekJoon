#11047

lst = input().split()
coin = []
n = int(lst[0])
total = int(lst[1])
tmp = 0
cnt = 0

for x in range(n):
    coin.append(int(input()))

coin = sorted(coin, reverse=True)

while(total > 0):
    if coin[tmp] <= total:
        total -= coin[tmp]
        cnt += 1
    else:
        tmp += 1

print(cnt)