import sys

studentNum = int(input())
classL = list()
maxS = 0
idx = 0

for i in range(studentNum):
    stu = list(map(int, sys.stdin.readline().rstrip().split()))
    classL.append(stu)

for student in range(studentNum):
    ckStudent = [0 for x in range(studentNum)]
    for grade in range(5):
        for Class in range(studentNum):
            if ((student != Class) and (classL[student][grade] == classL[Class][grade])):
                ckStudent[Class] = 1
    if (maxS < ckStudent.count(1)):
        maxS = ckStudent.count(1)
        idx = student

print(idx + 1)