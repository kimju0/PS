#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,x,y,res,cur;
vector<pair<int,int>> coor;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>x>>y;
    coor.push_back(make_pair(x,y));
  }
  sort(coor.begin(),coor.end());
  cur=coor[0].first;
  for(int i=0;i<N;i++){
    if(cur>coor[i].second) continue;
    if(cur<coor[i].first) {
      cur=coor[i].first;
    }
    res+=coor[i].second-cur;
    cur=coor[i].second;
  }
  cout<<res;
}