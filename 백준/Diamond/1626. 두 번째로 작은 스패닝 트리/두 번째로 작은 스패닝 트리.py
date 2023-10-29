import sys
import heapq
import math
from collections import deque
N,M=map(int,sys.stdin.readline().split())
tree=[[]for _ in range(N+1)]
MST=[[]for _ in range(N+1)]
INP=deque()
depth=[0]*(N+1)
max_square=int(math.log2(N-1))
parent=[[0 for i in range(N+1)] for j in range(max_square+1)]
max_w=[[set() for i in range(N+1)] for j in range(max_square+1)]
for i in range(M):
    u,v,w=map(int,sys.stdin.readline().split())
    INP.append((u,v,w))
    tree[u].append((w,v))
    tree[v].append((w,u))
check=[0]*(N+1)
heap=[]#(w,s,e)
check[1]=1
depth[1]=0
parent[0][1]=-1#1번노드는 루트노드
sum_MST=0
for i in tree[1]:
    heapq.heappush(heap,(i[0],1,i[1]))
for i in range(1,N):
    while heap and check[heap[0][2]]!=0:
        cur=heapq.heappop(heap)
    if not heap:#최소 스패닝트리가 없는 경우
        print(-1)
        sys.exit()
    cur=heapq.heappop(heap)
    sum_MST+=cur[0]
    MST[cur[1]].append(cur[2])
    MST[cur[2]].append(cur[1])
    check[cur[2]]=1
    depth[cur[2]]=depth[cur[1]]+1
    parent[0][cur[2]]=cur[1]
    max_w[0][cur[2]].add(cur[0])
    for i in tree[cur[2]]:
        if check[i[1]]==1:continue
        heapq.heappush(heap,(i[0],cur[2],i[1]))

#setPARENT
for k in range(1,max_square+1):
    for n in range(2,N+1):
        if int(math.log2(depth[n]))<k: continue
        parent[k][n]=parent[k-1][parent[k-1][n]]
        max_w[k][n]=max_w[k-1][n]
        max_w[k][n]=max_w[k][n]|max_w[k-1][parent[k-1][n]]

#두 번째 MST가 존재하지 않는 경우
#if M<=N-1:
#    print(-1)
#    sys.exit()

def binary_search():
    arr=list(lca_W)
    arr.sort()
    s,e=0,len(arr)-1
    ret=-1
    while s<=e:
        m=int((s+e)/2)
        if arr[m]<appended: 
            s=m+1
            ret=arr[m]
        else: e=m-1
    return ret
#쿼리마다 실행
res=200000*50000
for i in range(len(INP)):
    poped=INP.popleft()
    appended=poped[2]
    v1=poped[0]
    v2=poped[1]
    lca_W=set()

    if depth[v1]>depth[v2]: v1,v2=v2,v1#v2가 더 깊거나 같은 위치에 있음
    while depth[v1]!=depth[v2]:
        d=0
        for j in range(int(math.log2(depth[v2])),-1,-1):
            d=j
            if depth[parent[j][v2]]>=depth[v1]: break
        lca_W=lca_W|max_w[d][v2]
        v2=parent[d][v2]
    while v1!=v2:
        d=0
        for j in range(int(math.log2(depth[v2])),-1,-1):
            d=j
            if parent[j][v1]!=parent[j][v2]: break
        lca_W=lca_W|max_w[d][v2]
        v2=parent[d][v2]
        lca_W=lca_W|max_w[d][v1]
        v1=parent[d][v1]
    #이분탐색을 통해 appended보다 작은 가장 큰 간선 찾기
    ret=binary_search()
    if ret==-1: continue
    if res>sum_MST+appended-ret: res=sum_MST+ appended-ret
if res!=200000*50000: print(res)
else: print(-1)