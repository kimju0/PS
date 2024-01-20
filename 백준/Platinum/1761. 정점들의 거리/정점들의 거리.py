from sys import stdin
from collections import deque
import math

input = stdin.readline

N = int(input())
lcaTable = [[(-1, -1) for j in range(16)] for i in range(N + 1)]  # (부모 노드, 가중치)
depth = [0 for _ in range(N + 1)]
GRAPH = [[] for _ in range(N + 1)]
logTable = [0] * (N + 1)  # 각 노드별로 최대 몇 승번째 부모까지 존재 하는지
maxLog = 0


def set_parent():
    global lcaTable, depth, logTable, maxLog

    queue = deque([1])
    lcaTable[1][0] = (0, 0)
    depth[1] = 0
    logTable[1] = -1
    while queue:
        cur = queue.popleft()
        for target in GRAPH[cur]:
            if lcaTable[target[0]][0][0] != -1:  # 이미 부모가 지정된 경우
                continue
            queue.append(target[0])
            lcaTable[target[0]][0] = (cur, target[1])
            depth[target[0]] = depth[cur] + 1
            logTable[target[0]] = int(math.log2(depth[target[0]]))
            if maxLog < logTable[target[0]]:
                maxLog = logTable[target[0]]


def set_lca_table():
    global lcaTable
    for log in range(1, maxLog + 1):
        for i in range(1, N + 1):
            if logTable[i] < log: continue
            parent = lcaTable[lcaTable[i][log - 1][0]][log - 1][0]
            weight = lcaTable[i][log - 1][1] + lcaTable[lcaTable[i][log - 1][0]][log - 1][1]
            lcaTable[i][log] = (parent, weight)


def lca(a, b):
    ret = 0
    if depth[a] < depth[b]:
        a, b = b, a
    # a를 b의 위치까지 올리기
    while depth[a] > depth[b]:
        update = 0
        for log in range(1, logTable[a] + 1):
            if depth[lcaTable[a][log][0]] < depth[b]:
                update = log - 1
                break
        ret += lcaTable[a][update][1]
        a = lcaTable[a][update][0]
    assert depth[a] == depth[b], 'depth of a and b do not match'
    while a != b:
        update = 0
        for log in range(1, logTable[a] + 1):
            if lcaTable[a][log][0] == lcaTable[b][log][0]:
                update = log - 1
                break
        ret += lcaTable[a][update][1]
        ret += lcaTable[b][update][1]
        a = lcaTable[a][update][0]
        b = lcaTable[b][update][0]
    return ret


for i in range(N - 1):
    a, b, w = map(int, input().split())
    GRAPH[a].append([b, w])
    GRAPH[b].append([a, w])
set_parent()
set_lca_table()
M = int(input())
for i in range(M):
    a, b = map(int, input().split())
    print(lca(a, b))
