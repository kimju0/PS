#include <iostream>
#include <vector>

using namespace std;

int n,k,DP[11]={1,1,},sum;
vector<int> v;

void BackTracking(){
  if(n==0){
    cout<<v[0];
    for(int i=1;i<v.size();i++){
      cout<<'+'<<v[i];
    }
    return;
  }
  int temp=0;
  for(int i=1;i<=3;i++){
    temp+=DP[n-i];
    if(temp>=k){
      k-=(temp-DP[n-i]);
      n-=i;
      v.push_back(i);
      BackTracking();
      return;
    }
  }
  cout<<-1;
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>n>>k;
  
  for(int i=2;i<=n;i++){
    DP[i]=DP[i-1];
    if(i-2>=0) DP[i]+=DP[i-2];
    if(i-3>=0) DP[i]+=DP[i-3];
  }
  BackTracking();
}