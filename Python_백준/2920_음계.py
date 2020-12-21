inputLst = list(map(int,input().split()))
sortLst = list(range(1,9))
revLst = list(range(8, 0, -1))

if inputLst == sortLst:
    print("ascending")
elif inputLst == revLst:
    print("descending")
else:
    print("mixed")