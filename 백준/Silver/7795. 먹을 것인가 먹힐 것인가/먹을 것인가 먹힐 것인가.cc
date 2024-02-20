#include <iostream>
#include <algorithm>
using namespace std;
int T,N,M,A[20000],B[20000],res;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N>>M;
    for(int i=0;i<N;i++){
      cin>>A[i];
    }
    for(int i=0;i<M;i++){
      cin>>B[i];
    }
    sort(B,B+M);
    res=0;
    for(int i=0;i<N;i++){
      res+=lower_bound(B,B+M,A[i])-B;
    }
    cout<<res<<'\n';
  }
}