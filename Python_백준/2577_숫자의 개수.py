#세 개의 자연수 A, B, C가 주어질 때 A×B×C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.
#
# 예를 들어 A = 150, B = 266, C = 427 이라면
#
# A × B × C = 150 × 266 × 427 = 17037300 이 되고,
#
# 계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.

A = int(input())
B = int(input())
C = int(input())

result = str(A * B * C)

dic = {x:0 for x in range(10)}

for i in result:
    dic[int(i)] += 1

for j in dic:
    print(dic[j])