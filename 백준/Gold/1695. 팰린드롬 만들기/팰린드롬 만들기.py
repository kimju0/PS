from sys import stdin

input = stdin.readline

N = int(input())
arr = list(map(int, input().split()))
DP = [0] * N
for i in range(1, N):
    temp = DP[:i + 1]
    for j in range(i - 1, -1, -1):
        DP[j] = min(DP[j], DP[j + 1]) + 1
        if arr[i] == arr[j] and DP[j] > temp[j + 1]:
            DP[j] = temp[j + 1]
print(DP[0])
