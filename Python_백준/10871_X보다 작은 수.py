# 10 5
# 1 9 3 10 2 8 4 5 7 6

nLst = input().split()
n = nLst[-1]

s = input()

lst = s.split()
answerLst = []

for i in lst:
    if (int(i) < int(n)):
        answerLst.append(i)

answer = " ".join(answerLst)

print(answer)