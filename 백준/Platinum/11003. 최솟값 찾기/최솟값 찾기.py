from sys import stdin
from collections import deque

input = stdin.readline


def push(index):
    global deque
    if not deque:
        deque.append((A[index], index))
        return
    if deque[-1][0] < A[index]:
        deque.append((A[index], index))
    else:
        while deque and deque[-1][0] >= A[index]:
            deque.pop()
        deque.append((A[index], index))


def pop(index):
    global deque
    if deque[0][1] == index:
        deque.popleft()


N, L = map(int, input().split())
A = list(map(int, input().split()))
deque = deque()
D = [0] * N

for i in range(N - 1, -1, -1):
    if not deque:
        for j in range(L):
            push(i - j)
    elif i >= L - 1:
        push(i - L + 1)

    D[i] = deque[0][0]

    pop(i)

for i in range(N):
    print(D[i], end=' ')
