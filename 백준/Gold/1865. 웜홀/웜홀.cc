#include <iostream>
#include <vector>

using namespace std;

int TC,N,M,W,S,E,T;
vector<pair<int,int>> Graph[501];
int D[501];

bool BellmanFord(){
  D[1]=0;
  for(int i=0;i<N;i++){
    for(int j=1;j<=N;j++){
      for(auto e:Graph[j]){
        int curNode=j,nextNode=e.second,weight=e.first;
        if(D[nextNode]>D[curNode]+weight){
          D[nextNode]=D[curNode]+weight;
          if(i==N-1) return true;
        }
      }
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>TC;
  for(int tc=0;tc<TC;tc++){
    cin>>N>>M>>W;
    for(int i=1;i<=N;i++){
      Graph[i].clear();
      D[i]=5000001;
    }
    
    for(int i=0;i<M;i++){
      cin>>S>>E>>T;
      Graph[S].push_back(make_pair(T,E));
      Graph[E].push_back(make_pair(T,S));
    }
    for(int i=0;i<W;i++){
      cin>>S>>E>>T;
      Graph[S].push_back(make_pair(-T,E));
    }
    
    cout<<(BellmanFord()?"YES":"NO")<<endl;
  }
}