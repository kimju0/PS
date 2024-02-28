#include <iostream>

using namespace std;

int N, w[17][17], DP[65536][17];
//case of DP[i][j]
//0) 처리되지 않은 경우
//-1) 경로가 존재하지 않는 경우
//>0) 처리된 경우
void bfs(int visited, int curNode){
  //OUTPUT: DP[visited][curNode]
  //DP[i][j]: i를 방문했고 j에 있을 때, 나머지 도시들을 순회하는 데에 드는 비용
  //Exception: visited가 모든 도시인 경우, 1번 노드로 가는 비용
  //cout<<"DEBUG "<<visited<<" "<<curNode<<endl;
  if(visited==(1<<N)-1){
    if(w[curNode][1]!=0)
      DP[visited][curNode]=w[curNode][1];
    else
      DP[visited][curNode]=-1;
    //cout<<"inside exception "<<DP[visited][curNode]<<endl;
    return;
  }
  //cout<<1<<endl;
  int tempRes=0,targetNode;
  for(int i=1;i<=N;i++){
    targetNode=(1<<(i-1));
    
    if(w[curNode][i]==0||(visited|targetNode)==visited){
     continue;
    }
    
    tempRes=w[curNode][i];
    //cout<<"inside1 "<<tempRes<<endl;
    if(DP[visited|targetNode][i]==0) bfs(visited|targetNode,i);
    //cout<<"inside2 "<<DP[visited|targetNode][i]<<endl;
    if(DP[visited|targetNode][i]>0) tempRes+=DP[visited|targetNode][i];
    else continue;
    //cout<<"inside3 "<<tempRes<<endl;
    //cout<<"inside4 "<<DP[visited][curNode]<<endl;
    
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