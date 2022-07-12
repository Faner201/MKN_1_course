top, matching, graph = [], [], []

def dfs_kuhn(current_top):
    if matching[current_top]:
        return False
    matching[current_top] = True
    for i in graph[current_top]:
        if top[i] == -1 or dfs_kuhn(top[i]):
            top[i] = current_top
            return True
    return False
    
N, S = map(int, input().split())

graph = [[] for _ in range(S)]

for i in range(S):
    count = list(map(int, input().split()))
    for j in range(N):
        if (count[j]):
            graph[i].append(j)
top = [-1] * N

pin = 0

for i in range(S):
    matching = [False] * S
    pin += dfs_kuhn(i)
print(pin)