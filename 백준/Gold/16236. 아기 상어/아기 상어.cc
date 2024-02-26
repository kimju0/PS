#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, board[20][20],check[20][20], sharkLevel=2, res, nextLevel;
vector<tuple<int, int, int>> candidateFish;
pair<int, int> coorOfShark;
queue<pair<int, int>> q;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

void print(){
  cout<<"DEBUG"<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<board[i][j]<<' ';
    }
    cout<<endl;
  }
}

bool bfs(){//먹을 수 있는 물고기가 있는지 반환
  //print();
  int ty,tx,cy,cx,ny,nx,td,cd;
  candidateFish.clear();
  q=queue<pair<int, int>>();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      check[i][j]=0;
    }
  }
  
  q.push(coorOfShark);
  while(!q.empty()){
    auto popped=q.front();
    q.pop();
    cy=popped.first, cx=popped.second;
    for(int i=0;i<4;i++){
      ny=cy+dy[i], nx=cx+dx[i];
      if(ny>=N||nx>=N||ny<0||nx<0)
        continue;
      if(check[ny][nx]!=0)
        continue;
      if(board[ny][nx]>sharkLevel)
        continue;
      if(ny==coorOfShark.first && nx==coorOfShark.second)
        continue;
      
      check[ny][nx]=check[cy][cx]+1;
      if(board[ny][nx]!=0 && board[ny][nx]<sharkLevel)
        candidateFish.push_back(make_tuple(check[ny][nx],ny,nx));
        
      q.push(make_pair(ny,nx));
      //cout<<"PLS"<<endl;
    }
  }
  
  
  if(candidateFish.empty())
    return false;
  
  //cout<<"DEBUG"<<endl;
  
  int target=0;
  for(int i=0;i<candidateFish.size();i++){
    td=get<0>(candidateFish[target]),ty=get<1>(candidateFish[target]),tx=get<2>(candidateFish[target]);
    cd=get<0>(candidateFish[i]),cy=get<1>(candidateFish[i]),cx=get<2>(candidateFish[i]);
    if(td==cd){
      if(ty==cy){
        if(tx==cx){
          continue;
        }
        else{
          target=tx<cx?target:i;
        }
      }
      else{
        target=ty<cy?target:i;
      }
    }
    else{
      target=td<cd?target:i;
    }
  }
  
  nextLevel++;
  if(nextLevel==sharkLevel){
    sharkLevel++;
    nextLevel=0;
  }
  td=get<0>(candidateFish[target]),ty=get<1>(candidateFish[target]),tx=get<2>(candidateFish[target]);
  board[ty][tx]=0;
  res+=td;
  coorOfShark=make_pair(ty,tx);
  //cout<<ty<<' '<<tx<<endl;
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>board[i][j];
      if(board[i][j]==9){
        coorOfShark=make_pair(i,j);
        board[i][j]=0;
      }
    }
  }
  while(bfs());
  cout<<res;
}