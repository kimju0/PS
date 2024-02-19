#include <iostream>
using namespace std;
int x,y,month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string day[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>x>>y;
  int add=0;
  for(int i=1;i<x;i++){
    add+=month[i-1]%7;
    add%=7;
  }
  for(int i=1;i<y;i++){
    add++;
    add%=7;
  }
  cout<<day[add];
}