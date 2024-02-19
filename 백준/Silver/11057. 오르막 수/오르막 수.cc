#include <iostream>
using namespace std;
int N,DP[1001][10];
int main(){
  cin>>N;
  for(int i=0;i<10;i++){
    DP[1][i]=1;
  }
  for(int i=1;i<N;i++){
    for(int j=0;j<10;j++){
      for(int k=j;k<10;k++){
        DP[i+1][k]+=DP[i][j];
        DP[i+1][k]%=10007;
      }
    }
  }
  cout<<(DP[N][0]+DP[N][1]+DP[N][2]+DP[N][3]+DP[N][4]+DP[N][5]+DP[N][6]+DP[N][7]+DP[N][8]+DP[N][9])%10007;
}