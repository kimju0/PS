#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,K,c[30001],a,b,popped,r,p,DP[30001][3001];
bool check[30001];
vector<int> GRAPH[30001];
vector<pair<int,int>> SET;
queue<int> q;

void bfs(int i){
  r=c[i];
  p=1;
  q=queue<int>();
  check[i]=true;
  q.push(i);
  while(!q.empty()){
    popped=q.front();
    q.pop();
    for(auto e:GRAPH[popped]){
      if(check[e]==true) continue;
      check[e]=true;
      q.push(e);
      r+=c[e];
      p++;
    }
  }
  SET.push_back(make_pair(r,p));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  SET.push_back(make_pair(0,0));
  cin>>N>>M>>K;
  for(int i=1;i<=N;i++){
    cin>>c[i];
  }
  for(int i=0;i<M;i++){
    cin>>a>>b;
    GRAPH[a].push_back(b);
    GRAPH[b].push_back(a);
  }
  for(int i=1;i<=N;i++){
    if(check[i]==true) continue;
    bfs(i);
  }
  
  for(int i=1;i<=SET.size();i++){
    for(int j=1;j<K;j++){
      DP[i][j]=DP[i-1][j];
      if((j-SET[i-1].second>=0)&&(DP[i][j]<DP[i-1][j-SET[i-1].second]+SET[i-1].first))
        DP[i][j]=DP[i-1][j-SET[i-1].second]+SET[i-1].first;
    }
  }
  
  cout<<DP[SET.size()][K-1];
}