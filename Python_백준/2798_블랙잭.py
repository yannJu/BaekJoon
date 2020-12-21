#2798

n, m = map(int, input().split())
lst = list(map(int, input().split(' ')))
answer = []
max_answer = 0

for x in range(0, n - 2):
    for y in range(x + 1, n - 1):
        for z in range(y + 1, n):
           answer.append(lst[x] + lst[y] + lst[z])

for i in answer:
    if max_answer < i <= m:
        max_answer = i

print(max_answer)