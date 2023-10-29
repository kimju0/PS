import sys
sys.setrecursionlimit(10000000)
N=int(sys.stdin.readline())
arr=list(map(int,sys.stdin.readline().split()))
res=[-1]*N
lis=[0]
def answer(cur):
    if cur==-1:
        return
    answer(res[cur])
    print(arr[cur],end=' ')
def upperbound(s,e,target):
    ret=0
    m=(s+e)//2
    while s<e:
        if arr[lis[m]]<arr[target]:
            s=m+1
        elif arr[lis[m]]>=arr[target]:
            e=m
        m=(s+e)//2
    #print(m)
    if m!=0:res[target]=lis[m-1]
    else: res[target]=-1
    lis[m]=target
for i in range(1,N):
    if arr[lis[-1]]<arr[i]:
        res[i]=lis[-1]
        lis.append(i)
    else:
        upperbound(0,len(lis)-1,i)
print(len(lis))
answer(lis[-1])