#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int TC,n,m,t,s,g,h,a,b,d,cd;
vector<pair<int,int>> graph[2001];
vector<int> RES;
pair<int,bool> D[2001];
bool candidate[2001];
priority_queue<pair<int,pair<int,bool>>> pq;
pair<int,pair<int,bool>>popped;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>TC;
  for(int tc=0;tc<TC;tc++){
    for(int i=1;i<=2000;i++){
      graph[i].clear();
      D[i]={2000001,false};
      candidate[i]=false;
    }
    pq=priority_queue<pair<int,pair<int,bool>>>();
    RES.clear();
    
    cin>>n>>m>>t;
    cin>>s>>g>>h;
    for(int i=0;i<m;i++){
      cin>>a>>b>>d;
      graph[a].push_back(make_pair(d,b));
      graph[b].push_back(make_pair(d,a));
    }
    for(int i=0;i<t;i++){
      cin>>cd;
      candidate[cd]=true;
    }
    
    bool flag=false;
    D[s]={0,flag};
    pair<int,bool>e={s,flag};
    pq.push(make_pair(0,e));
    while(!pq.empty()){
      popped=pq.top();
      pq.pop();
      int tPair=-(popped.first),tNode=popped.second.first,tBool=popped.second.second;
      for(auto e: graph[tNode]){
        int nextPair=tPair+e.first,nextNode=e.second,nextBool=tBool;
        if((tNode==g&&nextNode==h)||(tNode==h&&nextNode==g))
          nextBool=true;
        e={nextNode,nextBool};
        if(D[nextNode].first>nextPair){
          D[nextNode]={nextPair,nextBool};
          pq.push(make_pair(-nextPair,e));
        }
        else if(nextBool==true&&D[nextNode].first==nextPair&&D[nextNode].second==false){
          D[nextNode]={nextPair,nextBool};
          pq.push(make_pair(-nextPair,e));
        }
      }
    }
    
    for(int i=1;i<=n;i++){
      if(D[i].second==true&&candidate[i]==true)
        RES.push_back(i);
    }
    sort(RES.begin(),RES.end());
    for(int i=0;i<RES.size();i++){
      cout<<RES[i]<<' ';
    }
    cout<<endl;
  }
}