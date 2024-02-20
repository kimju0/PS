#include <iostream>
using namespace std;
int N,input[32][32];
long long board[32][32][3];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>input[i][j];
    }
  }
  
  board[0][1][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(input[i][j]==1) continue;
    
      //state: 0
      if(j-1>=0&&input[i][j-1]!=1){
        board[i][j][0] += board[i][j-1][0];
        board[i][j][0] += board[i][j-1][2];
      }
      
      //state: 1
      if(i-1>=0&&input[i-1][j]!=1){
        board[i][j][1] += board[i-1][j][1];
        board[i][j][1] += board[i-1][j][2];
      }
      
      //state: 2
      if(i-1>=0&&j-1>=0&&input[i-1][j-1]!=1&&input[i-1][j]!=1&&input[i][j-1]!=1){
        board[i][j][2]+=board[i-1][j-1][2];
        board[i][j][2]+=board[i-1][j-1][1];
        board[i][j][2]+=board[i-1][j-1][0];
      }
    }
  }
  cout<<board[N-1][N-1][0]+board[N-1][N-1][1]+board[N-1][N-1][2];
}