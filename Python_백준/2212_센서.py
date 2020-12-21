#2212

s_N = int(input()) #센서 수
k_N = int(input()) #집중국 수
lst = list(map(int, input().split())) #센서 위치
lst.sort()
lst_tm = [0] * (s_N - 1)

for x in range(s_N - 1):
    lst_tm[x] = lst[x + 1] - lst[x]

lst_tm.sort()

for _ in range(k_N - 1):
    lst_tm.remove(max(lst_tm))

print(sum(lst_tm))