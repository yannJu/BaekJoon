#9095
# 1 = (1)
# 2 = (1 + 1) (2)
# 3 = (1 + 1 + 1) (1 + 2) (2 + 1) (3)
# 4 = (1 + 1 + 1+ 1) (1 + 1 + 2) (1 + 2 + 1) (1 + 3) -> 1 + 3에 해당하는것들
#     (2 + 1 + 1) (2 + 2) -> 2 + 2에 해당하는 것들
#     (3 + 1) -> 3 + 1에 해당하는 것들

def sumCycle(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        return sumCycle(n - 1) + sumCycle(n - 2) + sumCycle(n - 3)

h = int(input())

for _ in range(h):
    n = int(input())
    print(sumCycle(n))