# import sys
#
# n = int(input())
# lst = []
# cnt = 1
#
# for i in range(n):
#     a = sys.stdin.readline().replace("\n", "")
#     b = a.split()
#     lst.append(b)
#
# for j in lst:
#     result = 0
#     for l in j:
#         result += int(l)
#     print("Case #{}: {}".format(cnt, result))
#     cnt += 1

import sys

n = int(input())
lst = []
cnt = 1

for i in range(n):
    a = sys.stdin.readline().replace("\n", "")
    b = a.split()
    lst.append(b)

for j in lst:
    result = 0
    for l in j:
        result += int(l)
    print("Case #{}: {} + {} = {}".format(cnt, lst[cnt-1][0], lst[cnt-1][1], result))
    cnt += 1