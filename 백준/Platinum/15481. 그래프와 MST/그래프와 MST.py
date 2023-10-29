import sys
import heapq
import math
from collections import deque
N,M=map(int,sys.stdin.readline().split())
tree=[[]for _ in range(N+1)]
INP=deque()
depth=[0]*(N+1)
max_square=int(math.log2(N-1))
parent=[[0 for i in range(N+1)] for j in range(max_square+1)]
max_w=[[0 for i in range(N+1)] for j in range(max_square+1)]
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
    cur=heapq.heappop(heap)
    while check[cur[2]]!=0:
        cur=heapq.heappop(heap)
    sum_MST+=cur[0]
    check[cur[2]]=1
    depth[cur[2]]=depth[cur[1]]+1
    parent[0][cur[2]]=cur[1]
    max_w[0][cur[2]]=cur[0]
    for i in tree[cur[2]]:
        if check[i[1]]==1:continue
        heapq.heappush(heap,(i[0],cur[2],i[1]))

#setPARENT
for k in range(1,max_square+1):
    for n in range(2,N+1):
        if int(math.log2(depth[n]))<k: continue
        parent[k][n]=parent[k-1][parent[k-1][n]]
        max_w[k][n]=max(max_w[k-1][n] , max_w[k-1][parent[k-1][n]])
for i in range(len(INP)):
    poped=INP.popleft()
    appended=poped[2]
    v1=poped[0]
    v2=poped[1]
    lca_max_W=0
    if depth[v1]>depth[v2]: v1,v2=v2,v1#v2가 더 깊거나 같은 위치에 있음
    while depth[v1]!=depth[v2]:
        d=0
        for j in range(int(math.log2(depth[v2])),-1,-1):
            d=j
            if depth[parent[j][v2]]>=depth[v1]: break
        if lca_max_W<max_w[d][v2]:lca_max_W=max_w[d][v2]
        v2=parent[d][v2]
    while v1!=v2:
        d=0
        for j in range(int(math.log2(depth[v2])),-1,-1):
            d=j
            if parent[j][v1]!=parent[j][v2]: break
        if lca_max_W<max_w[d][v2]:lca_max_W=max_w[d][v2]
        v2=parent[d][v2]
        if lca_max_W<max_w[d][v1]:lca_max_W=max_w[d][v1]
        v1=parent[d][v1]
    print(sum_MST+appended-lca_max_W)