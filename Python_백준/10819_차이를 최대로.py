'''
문제
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

예제 입력 1 
6
20 1 15 8 4 10
예제 출력 1 
62
'''
import sys
N = int(input()) #ary Length
lst = list(map(int, sys.stdin.readline().split())) #Ary
ckLst = [] #ckLst
mxResult = -1 #최종 결과

def ckMaxDiff(n):
    global lst, ckLst
    m = -1 #현재값과 가장 차이가 많이나는 값의 차이값
    midx = -1 #현재값과 가장 차이가 많이나는 값의 idx
    
    # --- lst를 다 반복하면서 차이가 가장 큰 값을 찾음 ---
    for i in range(len(lst)):
        if (n == lst[i]): continue
        if (abs(n - lst[i])) > m and ckLst[i] == 0: 
            m = abs(n - lst[i])
            midx = i
    
    if midx < 0: return 0 #마지막 원소인 경우 0 반환
    ckLst[midx] = 1 #ckLst를 체크
    #print(ckLst)
    m += ckMaxDiff(lst[midx]) #사이값에 더해줌으로써 값을 구함
    return m
    
for i in range(len(lst)):
    ckLst = [0 for j in range(len(lst))]
    ckLst[i] = 1
    #print("idx : ", i)
    mxResult = max(mxResult, ckMaxDiff(lst[i]))

print(mxResult)