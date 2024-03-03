#include <iostream>

using namespace std;

int n,k,coin[101],DP[101][10001];

int CaseOfUse(int i,int j){
  if(j-coin[i]<0) return -1;
  if(DP[i][j-coin[i]]==-1) return -1;
  return DP[i][j-coin[i]]+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>coin[i];
  }
  for(int i=1;i<=k;i++){
    DP[0][i]=-1;
  }
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(CaseOfUse(i,j)==-1&&DP[i-1][j]==-1)
        DP[i][j]=-1;
      else if(CaseOfUse(i,j)==-1)
        DP[i][j]=DP[i-1][j];
      else if(DP[i-1][j]==-1)
        DP[i][j]=CaseOfUse(i,j);
      else
        DP[i][j]=min(CaseOfUse(i,j),DP[i-1][j]);
    }
  }
  cout<<DP[n][k];
}