#include <iostream>
using namespace std;
int a,b,c,DP[51][51][51];
int recur(int a,int b,int c){
  if(a<=0||b<=0||c<=0) {
    return 1;
  }
  if(DP[a][b][c]!=0) return DP[a][b][c];
  if(a>20||b>20||c>20){
    DP[a][b][c]=recur(20,20,20);
  }
  else if(a<b&&b<c){
    DP[a][b][c]=recur(a,b,c-1)+recur(a,b-1,c-1)-recur(a,b-1,c);
  }
  else{
    DP[a][b][c]=recur(a-1,b,c)+recur(a-1,b-1,c)+recur(a-1,b,c-1)-recur(a-1,b-1,c-1);
  }
  return DP[a][b][c];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(true){
    cin>>a>>b>>c;
    if(a==-1&&b==-1&&c==-1) return 0;
    cout<<"w("<<a<<", "<<b<<", "<<c<<") = " <<recur(a,b,c)<<'\n';
  }
}