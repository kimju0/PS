#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,C,res,element;
vector<long long> v[2],state,input[2];

void Combi(int r,int ind){
  if(state.size()==r){
    long long sum=0;
    for(auto e:state)
      sum+=input[ind][e];
    v[ind].push_back(sum);
    return;
  }
  int i=state.size()>0?state.back()+1:0;
  for(;i<input[ind].size();i++){
   state.push_back(i);
   Combi(r,ind);
   state.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N>>C;
  for(int i=0;i<N;i++){
    cin>>element;
    if(i<N/2)
      input[0].push_back(element);
    else
      input[1].push_back(element);
  }
  
  v[0].push_back(0);
  v[1].push_back(0);
  for(int i=1;i<=input[0].size();i++){
    Combi(i,0);
  }
  for(int i=1;i<=input[1].size();i++){
    Combi(i,1);
  }
  sort(v[1].begin(),v[1].end());
  
  for(int i=0;i<v[0].size();i++){
    if(C-v[0][i]>=v[1].back()){
      res+=v[1].size();
      continue;
    }
    res+=(upper_bound(v[1].begin(),v[1].end(),C-v[0][i])-v[1].begin());
  }
  
  cout<<res;
}