import sys
def upperbound(target):
    s,e=0,n*(n-1)+1
    if new_n[e]<=target: return n*(n-1)+2
    while s<e:
        mid=(s+e)//2
        if new_n[mid]<=target:s=mid+1
        else: e=mid
    return s
def lowerbound(target):
    s,e=0,n*(n-1)+1
    if new_n[e]<target: return n*(n-1)+2
    while s<e:
        mid=(s+e)//2
        if new_n[mid]<target:s=mid+1
        else:e=mid
    return s
size=int(sys.stdin.readline())
m,n=map(int,sys.stdin.readline().split())
arr_m,arr_n=[],[]
for i in range(m):
    inp=int(sys.stdin.readline())
    arr_m.append(inp)
for i in range(n):
    inp=int(sys.stdin.readline())
    arr_n.append(inp)
new_m,new_n=[],[]
for i in range(m):
    subtotal=arr_m[i]
    new_m.append(subtotal)
    for j in range(1,m-1):
        new_ind=i+j
        if new_ind>=m:new_ind-=m
        subtotal+=arr_m[new_ind]
        new_m.append(subtotal)
new_m.append(subtotal+arr_m[-2])
new_m.append(0)
for i in range(n):
    subtotal=arr_n[i]
    new_n.append(subtotal)
    for j in range(1,n-1):
        new_ind=i+j
        if new_ind>=n:new_ind-=n
        subtotal+=arr_n[new_ind]
        new_n.append(subtotal)
new_n.append(subtotal+arr_n[-2])
new_n.append(0)
new_n.sort()
res=0
for i in range(m*(m-1)+2):
    res+=upperbound(size-new_m[i])-lowerbound(size-new_m[i])
print(res)