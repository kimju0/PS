import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
N, R, Q = map(int, input().split())
TREE = [[] for _ in range(N + 1)]
DP = [0] * (N + 1)


def makeTree(node):
    DP[node] = 1
    for i in TREE[node]:
        if DP[i] == 0:
            makeTree(i)
            DP[node] += DP[i]


for i in range(N - 1):
    U, V = map(int, input().split())
    TREE[U].append(V)
    TREE[V].append(U)
makeTree(R)
for i in range(Q):
    print(DP[int(input())])
