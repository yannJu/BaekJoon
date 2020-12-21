# N개의 정수가 주어진다.
# 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
#
# 예제입력1
# 5
# 20 10 35 30 7
# 출력1
# 7 35

n = int(input())
lst = input().split()

for i in range(n):
    lst[i] = int(lst[i])

answer = ""

answer += str(max(lst)) + " " + str(min(lst))

print(answer)