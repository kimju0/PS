#include <iostream>
using namespace std;
int N, M, L, K, cover = 1, coor[100][2];

int calc_cover(int maxY, int maxX){
  int ret = 0,curY,curX;
  for(int i=0;i<K;i++){
    curY=coor[i][1],curX=coor[i][0];
    if(curY>maxY || curY<maxY-L) continue;
    if(curX>maxX || curX<maxX-L) continue;
    ret++;
  }
  return ret;
}

int main(){
  cin>>N>>M>>L>>K;
  for(int i=0;i<K;i++){
    cin >> coor[i][0] >> coor[i][1];
  }
  int maxY, maxX;
  for(int i=0;i<K;i++){ //maxY
    maxY=coor[i][1];
    for(int j=0;j<K;j++){ //maxX
      maxX=coor[j][0];
      if(maxY<coor[j][1] || maxX<coor[i][0]) continue;
      int ret=calc_cover(maxY,maxX);
      cover = cover>ret?cover:ret;
    }
  }
  cout << K - cover;
  return 0;
}