T = int(input())
for i in range(T):
    a, b = map(str, input().split())
    if a == b:
        print("OK")
    else:
        print("ERROR")