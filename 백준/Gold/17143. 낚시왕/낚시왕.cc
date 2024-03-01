#include <iostream>
#include <vector>

using namespace std;

int R,C,M,y,x,res,personX,board[100][100],tempBoard[100][100];
bool v[10000];
int speed[10000],dir[10000],sizee[10000];
int dy[5]={0,-1,1,0,0},dx[5]={0,0,0,1,-1};
vector<pair<int,int>> shark;

void ClearTempBoard(){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      tempBoard[i][j]=0;
    }
  }
}

void moveToBoard(){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      board[i][j]=tempBoard[i][j];
    }
  }
}

void processTempBoard(int y,int x,int i){
  int cell=tempBoard[y][x];
  if(cell==0){
    tempBoard[y][x]=i+'A';
    return;
  }
  if(sizee[cell-'A']>sizee[i]){
    v[i]=true;
  }
  else{
    v[cell-'A']=true;
    tempBoard[y][x]=i+'A';
  }
}

void SharkMove(){
  for(int i=0;i<shark.size();i++){
    if(v[i]==true)continue;
    int dis=speed[i];
    if(dir[i]<=2){
      dis%=((R-2)*2+2);
    }
    else{
      dis%=((C-2)*2+2);
    }
    int cy=shark[i].first,cx=shark[i].second;
    while(dis>0){
      int d=dir[i];
      if(cy+dy[d]>=R||cx+dx[d]>=C||cy+dy[d]<0||cx+dx[d]<0){
        if(d==1) dir[i]=2;
        else if(d==2) dir[i]=1;
        else if(d==3) dir[i]=4;
        else dir[i]=3;
        d=dir[i];
      }
      cy+=dy[d],cx+=dx[d];
      dis--;
    }
    shark[i]=make_pair(cy,cx);
    processTempBoard(cy,cx,i);
  }
}

void ManMove(){
  for(int i=0;i<R;i++){
    int t=board[i][personX];
    if(t!=0){
      res+=sizee[t-'A'];
      v[t-'A']=true;
      board[i][personX]=0;
      break;
    }
  }
  
  ClearTempBoard();
  SharkMove();
  moveToBoard();
  
  personX++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>R>>C>>M;
  for(int i=0;i<M;i++){
    cin>>y>>x>>speed[i]>>dir[i]>>sizee[i];
    shark.push_back(make_pair(y-1,x-1));
    board[y-1][x-1]=i+'A';
  }
  
  while(personX<C){
    ManMove();
  }
  
  cout<<res;
}