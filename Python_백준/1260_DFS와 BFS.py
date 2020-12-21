#1260
import queue

#dfs

N, M, V = map(int, input().split)

G = [[] for _ in range(N + 1)]

for i in range(M):
    v, u = map(int, input().split())
    G[v].append(u) # v->u
    G[u].append(v) # u->v

for v in range(1, N + 1):
    G[v].sort()

visit = [False for _ in range(N + 1)] #방문횟수

def dfs(v):
    visit[v] = True
    print(v, end="")
    for u in G(v):
        if not visit[u]:
            dfs(u)

dfs(v)
print()

#bfs
visit = [False for _ in range(N + 1)] #방문횟수

q = queue.Queue()
q.put(v)
while not q.empty():
    v = q.get()

    if visit[v]:
        continue

    visit[v] = True
    print(v, end="")

    for u in G(v):
        if not visit[u]:
            q.put(u)