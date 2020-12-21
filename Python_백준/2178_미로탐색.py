#2178

import queue
N, M = map(int, input.split())

Map = [[False for x in range(M)] for y in range(M)] #장애물 유무

for y in range(N):
    r = input()
    for x in range(M):
        if r[x] == 0:
            Map[y][x] = True

q = queue.Queue()

q.put([0, 0, 0])#좌표, cnt
dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]#상하좌우
visit = [[False for x in range(M)] for y in range(M)]
while not q.empty():
    t = q.get()

    if t[:2] == [M -1, N - 1]:
        break

    for d in dir:
        x = t[0] + d[0]
        y = t[1] + d[1]
        visit[y][x] = True
        q.put([x, y, t[2] + 1])

