#11399

n = int(input())
lst = list(map(int, input().split()))
lst = sorted(lst)
total = 0
wait_time = 0

for x in lst:
    wait_time += x
    total += wait_time

print(total)