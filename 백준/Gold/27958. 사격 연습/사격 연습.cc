#include <iostream>
using namespace std;
int N, K, board[8][8], bullet[5], state[5], res;
int dy[4]={1,-1,0,0},dx[4]={0,0,1,-1};

void simulate(){
  int tempRes=0, tempBoard[8][8],tempPointBoard[8][8];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      tempBoard[i][j]=board[i][j];
      tempPointBoard[i][j]=board[i][j];
    }
  }
  //cout<<"DEBUG"<<endl;
  for(int i=0;i<K;i++){
    //cout<<"state[i] : "<<state[i]<<endl;
  }
  for(int i=0;i<K;i++){
    //cout<<"DEBUG"<<endl;
    int curY=state[i],curX=0,bulletAttack=bullet[i];
    while(curX<N&&tempBoard[curY][curX]<=0){
      curX++;
    }
    if(curX>=N) continue;
    if(tempPointBoard[curY][curX]>=10){
      tempRes+=tempPointBoard[curY][curX];
      tempBoard[curY][curX]=0;
      tempPointBoard[curY][curX]=0;
    }
    else if(tempBoard[curY][curX] <= bulletAttack){
      tempRes+=tempPointBoard[curY][curX];
      for(int i=0;i<4;i++){
        int ny=curY+dy[i],nx=curX+dx[i];
        if(ny>=N||nx>=N||ny<0||nx<0)continue;
        if(tempPointBoard[ny][nx]>0)continue;
        tempPointBoard[ny][nx]=tempPointBoard[curY][curX]/4;
        tempBoard[ny][nx]=tempPointBoard[curY][curX]/4;
      }
      tempBoard[curY][curX]=0;
      tempPointBoard[curY][curX]=0;
    }
    else{
      tempBoard[curY][curX]-=bulletAttack;
    }
  }
  if(res<tempRes) res=tempRes;
  //cout<<"DEBUG-end"<<endl;
}

void back_tracking(int cnt){
  if(cnt == K){
    //cout<<"DEBUG"<<endl;
    simulate();
    return;
  }
  for(int i=0;i<N;i++){
    state[cnt]=i;
    back_tracking(cnt+1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N>>K;
  //cout<<"DEBUG"<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>board[i][j];
    }
  }
  //cout<<"DEBUG"<<endl;
  for(int i=0;i<K;i++){
    cin>>bullet[i];
  }
  //cout<<"DEBUG"<<endl;
  back_tracking(0);
  cout<<res;
  return 0;
}