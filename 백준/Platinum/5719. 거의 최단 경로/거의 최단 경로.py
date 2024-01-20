from sys import stdin
import heapq
from collections import deque

input = stdin.readline

D = None
isValid = [[True for j in range(501)] for i in range(501)]


def remove_edge():
    global isValid
    stack = deque([E])
    while stack:
        cur = stack.pop()
        for e in D[cur][1]:
            if not isValid[e][cur]:
                continue
            isValid[e][cur] = False
            stack.append(e)


while True:
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        break
    S, E = map(int, input().split())
    Graph = [[] for i in range(N)]
    D = [[500001, []] for i in range(N)]
    heap = []
    for i in range(M):
        U, V, P = map(int, input().split())
        Graph[U].append([V, P])
        isValid[U][V] = True
    D[S] = [0, []]
    for target in Graph[S]:
        element = [target[1], S, target[0]]
        heapq.heappush(heap, element)
    while heap:
        popped = heapq.heappop(heap)
        if D[popped[2]][0] > popped[0]:
            D[popped[2]][0] = popped[0]
            D[popped[2]][1].clear()
            D[popped[2]][1].append(popped[1])
            for target in Graph[popped[2]]:
                element = [target[1] + popped[0], popped[2], target[0]]
                heapq.heappush(heap, element)
        elif D[popped[2]][0] == popped[0]:
            D[popped[2]][1].append(popped[1])
    remove_edge()
    heap = []
    D = [500001 for i in range(N)]
    D[S] = 0
    for target in Graph[S]:
        if not isValid[S][target[0]]: continue
        heapq.heappush(heap, [target[1], target[0]])
    while heap:
        popped = heapq.heappop(heap)
        if D[popped[1]] > popped[0]:
            D[popped[1]] = popped[0]
            for target in Graph[popped[1]]:
                if not isValid[popped[1]][target[0]]: continue
                heapq.heappush(heap, [D[popped[1]] + target[1], target[0]])
    if D[E] == 500001:
        print(-1)
    else:
        print(D[E])
