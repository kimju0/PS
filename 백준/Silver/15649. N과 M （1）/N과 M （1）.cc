#include <iostream>
using namespace std;
int N, M,res[8],hashTable[9];
void backTracking(int cnt){
  if(cnt==M){
    for(int i=0;i<M;i++){
      cout<<res[i]<<" ";
    }
    cout<<'\n';
    return;
  }
  for(int i=1;i<=N;i++){
    if(hashTable[i]==1)continue;
    res[cnt]=i;
    hashTable[i]=1;
    backTracking(cnt+1);
    hashTable[i]=0;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N>>M;
  backTracking(0);
  return 0;
}