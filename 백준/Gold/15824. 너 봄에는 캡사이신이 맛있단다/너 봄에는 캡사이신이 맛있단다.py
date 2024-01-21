from sys import stdin

input = stdin.readline

N = int(input())
menu = list(map(int, input().split()))
menu.sort()
result = 0
weight = 2
for i in range(2, N + 1):  # 시그마 표현으로는 i=2~N => 인덱싱 때문에 약간 조정
    result += (weight - 1) * (menu[i - 1] - menu[N - i])
    weight *= 2
print(result % 1000000007)
