import sys
N,M,K=map(int,sys.stdin.readline().split())
num,d=1,0#노드 개수, 깊이 //루트의 깊이가 0
while 2**d<N:
    d+=1
    num+=2**d
seg_tree=[0]*(num+1)
cur=num-2**d+1
for i in range(N):
    seg_tree[cur+i]=int(sys.stdin.readline())
cur+=(N-1)
while cur!=0:
    seg_tree[cur//2]+=seg_tree[cur]
    cur-=1
for i in range(M+K):
    statement=list(map(int,sys.stdin.readline().split()))
    if statement[0]==1:
        cur,delta=num-2**d+statement[1],statement[2]-seg_tree[statement[1]+num-2**d]
        while cur!=0:
            seg_tree[cur]+=delta
            cur=cur//2
    elif statement[0]==2:
        ret=0
        s,e=statement[1]+num-2**d,statement[2]+num-2**d
        while s<=e:
            if s//2==(s-1)//2:
                ret+=seg_tree[s]
                s=s//2+1
            else: s=s//2
            if e//2==(e+1)//2:
                ret+=seg_tree[e]
                e=e//2-1
            else: e=e//2
        print(ret)