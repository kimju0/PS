#include <iostream>

using namespace std;

int N, w[17][17], DP[65536][17];
void bfs(int visited, int curNode){
  if(visited==(1<<N)-1){
    if(w[curNode][1]!=0)
      DP[visited][curNode]=w[curNode][1];
    else
      DP[visited][curNode]=-1;
    return;
  }
  int tempRes=0,targetNode;
  for(int i=1;i<=N;i++){
    targetNode=(1<<(i-1));
    
    if(w[curNode][i]==0||(visited|targetNode)==visited){
     continue;
    }
    
    tempRes=w[curNode][i];
    if(DP[visited|targetNode][i]==0) bfs(visited|targetNode,i);
    if(DP[visited|targetNode][i]>0) tempRes+=DP[visited|targetNode][i];
    else continue;
    
    if(DP[visited][curNode]==0||DP[visited][curNode]>tempRes)DP[visited][curNode]=tempRes;
  }
  
  if(DP[visited][curNode]==0) DP[visited][curNode] = -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin>>w[i][j];
    }
  }
  bfs(1,1);
  cout<<DP[1][1];
}