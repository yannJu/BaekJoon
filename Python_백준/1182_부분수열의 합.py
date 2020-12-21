#1182
import itertools

n, p = map(int, input().split())
lst = list(map(int, input().split(' ')))
cnt = 0

for x in range(1, len(lst) + 1):
    com_lst = list(itertools.combinations(lst, x))

    for y in com_lst:
        result = 0
        for z in y:
            result += z

        if result == p:
            cnt += 1

print(cnt)

#itertools.combinations 와 관련한 코드 함수화 해보기