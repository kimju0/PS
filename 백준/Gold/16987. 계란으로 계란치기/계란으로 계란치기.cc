#include <iostream>
using namespace std;
int N,S[8],W[8],res;
int state[8];//i번째 계란으로 state[i]번째 계란을 친다는 의미
void simulate(){
  int temp[8],tempRes=0;
  for(int i=0;i<N;i++){
    temp[i]=S[i];
  }
  for(int i=0;i<N;i++){
    if(temp[i]<=0) continue;
    if(temp[state[i]]<=0) continue;
    temp[state[i]]-=W[i];
    temp[i]-=W[state[i]];
    if(temp[state[i]]<=0) tempRes++;
    if(temp[i]<=0) tempRes++;
  }
  if(res<tempRes)res=tempRes;
}
void backTracking(int cnt){
  if(cnt==N){
    simulate();
    return;
  }
  for(int i=0;i<N;i++){
    if(cnt==i){
      continue;
    }
    state[cnt]=i;
    backTracking(cnt+1);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>S[i]>>W[i];
  }
  backTracking(0);
  cout<<res;
}