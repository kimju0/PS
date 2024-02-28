#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N,w[26],f[26],res;
string str[10];
priority_queue<pair<int,int>> pq;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>str[i];
  }
  
  for(int i=0;i<N;i++){
    //set w
    int weight=1;
    for(int j=str[i].size()-1; j>=0; j--){
      w[str[i][j]-'A']+=weight;
      weight*=10;
    }
  }
  
  //set f
  for(int i=0;i<26;i++){
    if(w[i]==0) continue;
    //cout<<i<<endl;
    pq.push(make_pair(w[i],i));
  }
  int i=9;
  while(!pq.empty()){
    f[pq.top().second]=i;
    pq.pop();
    i--;
  }
  
  //calc
  for(int i=0;i<26;i++){
    res+=w[i]*f[i];
  }
  cout<<res;
}