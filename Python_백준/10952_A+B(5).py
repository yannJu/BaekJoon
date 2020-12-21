while True:
    result = 0
    n = input()
    if n[0] == '0':
        break
    else:
        lst = n.split()
        for i in lst:
            result += int(i)
        print(result)