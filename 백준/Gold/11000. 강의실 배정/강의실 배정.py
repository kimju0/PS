import sys
import heapq
input = sys.stdin.readline
N=int(input())
heap=[]
res=0
assignment=[]
for i in range(N):
    s,e=map(int,input().split())
    assignment.append((s,e))
assignment.sort()
for i in range(N):
    cur=assignment[i]
    if heap and heap[0]<=cur[0]:
        heapq.heappop(heap)
        heapq.heappush(heap,cur[1])
    else:
        heapq.heappush(heap,cur[1])
        res+=1
print(res)