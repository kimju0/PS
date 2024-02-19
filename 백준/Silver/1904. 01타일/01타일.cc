#include <iostream>
using namespace std;
int N,DP[1000001]={0,1,2,};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  for(int i=3;i<=N;i++){
    DP[i]=DP[i-1]+DP[i-2];
    DP[i]%=15746;
  }
  cout<<DP[N];
}