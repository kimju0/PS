from sys import stdin

input = stdin.readline

N = int(input())
dpTable = [[[0 for _ in range(1024)] for _ in range(10)] for _ in range(N + 1)]
for i in range(1, 10):
    dpTable[1][i][1 << i] = 1
for i in range(2, N + 1):
    for j in range(10):
        if j != 0:
            for k in range(1024):  # 1 작은 수에서 현재 j로 확장되는 경우
                dpTable[i][j][k | (1 << j)] = (
                        dpTable[i][j][k | (1 << j)] % 1000000000 + dpTable[i - 1][j - 1][k] % 1000000000)
                dpTable[i][j][k | 1 << j] %= 1000000000
        if j != 9:
            for k in range(1024):  # 1 큰 수에서 현재 j로 확장되는 경우
                dpTable[i][j][k | (1 << j)] = (
                        dpTable[i][j][k | (1 << j)] % 1000000000 + dpTable[i - 1][j + 1][k] % 1000000000)
                dpTable[i][j][k | (1 << j)] %= 1000000000

res = 0
for i in range(10):
    res = res % 1000000000 + dpTable[N][i][1023] % 1000000000
    res %= 1000000000
print(res)
