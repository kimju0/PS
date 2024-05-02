#include <iostream>
using namespace std;
int T,N,tree[10001],track[10001],a,b;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    for(int i=1;i<=N;i++){
      tree[i]=0;
      track[i]=0;
    }
    for(int i=0;i<N-1;i++){
      cin>>a>>b;
      tree[b]=a;
    }
    cin>>a>>b;
    while(a!=0){
      track[a]=1;
      a=tree[a];
    }
    while(track[b]!=1){
      b=tree[b];
    }
    cout<<b<<endl;
  }
}