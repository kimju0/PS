#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,d,c,res;
vector<pair<int, int>> P;
priority_queue<int> pq;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  P.push_back(make_pair(0,0));
  for(int i=0;i<N;i++){
    cin>>d>>c;
    P.push_back(make_pair(d,c));
  }
  N++;
  sort(P.begin(),P.end());
  int beforeDay=P[N-1].first;
  for(int i=N-1;i>=0;i--){
    if(P[i].first<beforeDay){
      for(int j=0;j<beforeDay-P[i].first;j++){
        if(pq.empty()) break;
        res+=pq.top();
        pq.pop();
      }
      beforeDay=P[i].first;
    }
    pq.push(P[i].second);
  }
  cout<<res;
}