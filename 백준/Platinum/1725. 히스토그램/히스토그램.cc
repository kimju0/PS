#include <iostream>

using namespace std;

int n,h[100000],depth;
long long res;
pair<int,int> segmentTree[262143+1];

void SetSegmentTree(){
  for(int i=0;i<n;i++){
    segmentTree[(1<<depth)+i]=make_pair((1<<depth)+i,h[i]);
  }
  int target=1<<(depth+1)-1;
  for(int i=(1<<depth)+n;i<=target;i++){
    segmentTree[i]=make_pair(0,0);
  }
  target=(1<<depth)-1;
  while(target>0){
    int fir,sec,flag;
    if(segmentTree[target*2].second<segmentTree[target*2+1].second)
      flag=target*2;
    else flag=target*2+1;
    fir=segmentTree[flag].first;
    sec=segmentTree[flag].second;
    
    segmentTree[target]=make_pair(fir,sec);
    target--;
  }
}

int GetSegmentTree(int s,int e){
  int ret=s;
  while(s<=e){
    if(s%2){
      if(segmentTree[ret].second>segmentTree[s].second)
        ret=segmentTree[s].first;
      s+=1;
    }
    if(e%2==0){
      if(segmentTree[ret].second>segmentTree[e].second)
        ret=segmentTree[e].first;
      e-=1;
    }
    s/=2,e/=2;
  }
  return ret;
}

void Recur(int s,int e){
  if(s>e) return;
  int ret=GetSegmentTree(s,e);
  long long temp=segmentTree[ret].second;
  if(res<temp*(e-s+1))
    res=temp*(e-s+1);
  Recur(s,ret-1);
  Recur(ret+1,e);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  while((1<<depth)<n){
    depth++;
  }
  SetSegmentTree();
  Recur(1<<depth,(1<<depth)+n-1);
  cout<<res;
  res=0;
}