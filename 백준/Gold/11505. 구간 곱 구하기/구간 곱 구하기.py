from sys import stdin

input = stdin.readline


def calc_height():
    height = 0
    numLeafNode = 1
    while numLeafNode < N:
        height += 1
        numLeafNode *= 2
    return height


def set_segment_tree():
    global segmentTree
    base = 1 << height
    for i in range(N):
        segmentTree[base + i] = int(input())
    cur = base - 1
    while cur > 0:
        segmentTree[cur] = (segmentTree[cur * 2] * segmentTree[cur * 2 + 1]) % 1000000007
        cur -= 1


def update_segment_tree(ind, value):
    global segmentTree
    cur = (1 << height) - 1 + ind
    segmentTree[cur] = value
    cur //= 2
    while cur > 0:
        segmentTree[cur] = (segmentTree[cur * 2] * segmentTree[cur * 2 + 1]) % 1000000007
        cur //= 2


def get_segment_tree(s, e):
    res = 1
    s = (1 << height) - 1 + s
    e = (1 << height) - 1 + e
    while s <= e:
        if s % 2 == 1:
            res *= segmentTree[s]
            s += 1
        if e % 2 == 0:
            res *= segmentTree[e]
            e -= 1
        s //= 2
        e //= 2
        res %= 1000000007
    return res


N, M, K = map(int, input().split())
height = calc_height()
segmentTree = [0] * (1 << (height + 1))
set_segment_tree()
for i in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        update_segment_tree(b, c)
    else:
        print(get_segment_tree(b, c))
