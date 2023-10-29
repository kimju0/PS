import sys
from itertools import combinations
N,S=map(int,sys.stdin.readline().split())
arr=list(map(int,sys.stdin.readline().split()))
left_arr,right_arr=[0]*(2**(N//2)),[0]*2**(N-N//2)
tail_left,tail_right=1,1
def lowerBound(target):#target 이상 인덱스
  s,e=0,len(right_arr)
  if right_arr[-1]<target:return e+1
  while s<e:
    m=(s+e)//2
    if right_arr[m]>=target:e=m
    else:s=m+1
  return s
def upperBound(target):#target 초과 인덱스
  s,e=0,len(right_arr)
  if right_arr[-1]<target:return e+1
  while s<e:
    m=(s+e)//2
    if right_arr[m]>target:e=m
    else:s=m+1
  return s
for i in range(1,N//2+1):
  temp=list(combinations(arr[:N//2],i))
  for j in temp:
    left_arr[tail_left]=sum(j)
    tail_left+=1
for i in range(1,N-N//2+1):
  temp=list(combinations(arr[N//2:],i))
  for j in temp:
    right_arr[tail_right]=sum(j)
    tail_right+=1
right_arr.sort()
res=0
for i in left_arr:
  res+=upperBound(S-i)-lowerBound(S-i)
if S==0:res-=1
print(res)