import sys
import heapq
N=int(sys.stdin.readline())
heap=[]
inp=0
res=0
for i in range(N):
    inp=int(sys.stdin.readline())
    heapq.heappush(heap,inp)
if N==1:
    print(0)
    exit(0)
for i in range(N-1):
    t1,t2=heapq.heappop(heap),heapq.heappop(heap)
    heapq.heappush(heap,t1+t2)
    res+=(t1+t2)
print(res)