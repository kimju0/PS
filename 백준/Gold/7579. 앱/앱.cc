#include <iostream>

using namespace std;

int N,M,input[2][101],DP[101][10001],tot,res=1000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>input[0][i];
    }
    for(int i=1;i<=N;i++){
        cin>>input[1][i];
        tot+=input[1][i];
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<=tot;j++){
          DP[i][j]=DP[i-1][j];
          if(j-input[1][i]>=0&&DP[i][j]<DP[i-1][j-input[1][i]]+input[0][i])
            DP[i][j]=DP[i-1][j-input[1][i]]+input[0][i];
          if(M<=DP[i][j]&&res>j)
            res=j;
        }
    }
    
    cout<<res;
}