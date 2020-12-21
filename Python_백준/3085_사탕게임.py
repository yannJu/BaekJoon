#3085

n = int(input())
lst = []
ck = 0
max_cnt = 1

for _ in range(n):
    s_lst = list(input())
    lst.append(s_lst)

for r_x in range(n):
    cp_lst = []
    for x in lst[r_x]:
        cp_lst.append(x)

    for r_y in range(n - 1):
        cnt = 1
        if (cp_lst[r_y] != cp_lst[r_y+1]):
            fc = cp_lst[r_y]
            sc = cp_lst[r_y+1]
            cp_lst[r_y], cp_lst[r_y+1] = sc, fc
            lst[r_x] = cp_lst
        else:
            continue

        for r_z in lst:
            if(r_z[r_y] == ck):
                cnt += 1
            else:
                print("cnt:",cnt)
                if cnt > max_cnt:
                    max_cnt = cnt
                else:
                    cnt = 0
                break
            ck = r_z[r_y]
        lst[r_x][r_y] = fc
        lst[r_x][r_y+1] = sc

        print(max_cnt)

for c_x in range(n):
    for c_y in range(n - 1):
        cnt = 0
        if (lst[c_y][c_x] != lst[c_y+1][c_x]):
            fc = lst[c_y][c_x]
            sc = lst[c_y+1][c_x]
            lst[c_y][c_x], lst[c_y+1][c_x] = sc, fc
        else:
            continue

        for c_z in cp_lst:
            for n_z in range(len(c_z) - 1):
                if(c_z[n_z] == c_z[n_z+ 1]):
                    cnt += 1
                else:
                    if cnt > max_cnt:
                        max_cnt = cnt
                    break
        lst[c_y][c_x] = fc
        lst[c_y+1][c_x] = sc
        print(max_cnt)

print(max_cnt)