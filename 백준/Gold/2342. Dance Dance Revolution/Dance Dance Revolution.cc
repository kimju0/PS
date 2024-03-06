#include <iostream>
#include <vector>

using namespace std;

int e,DP[25][100001];
vector<int> input;

int Move(int s,int e){
  if(s==e) return 1;
  if(s==0) return 2;
  int d=e-s;
  d=d<0?-d:d;
  if(d%2==0) return 4;
  return 3;
}

int DynamicProgram(int i,int j){
  if(DP[i][j]!=0) return DP[i][j];
  if(j==input.size())return 0;
  int target=input[j];
  int leftFoot=i/5,rightFoot=i%5;
  int l=400001,r=400001;
  if(rightFoot!=target){
    l=Move(leftFoot,target)+DynamicProgram(target*5+rightFoot,j+1);
  }
  if(leftFoot!=target){
    r=Move(rightFoot,target)+DynamicProgram(leftFoot*5+target,j+1);
  }
  DP[i][j]=min(l,r);
  return DP[i][j];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>e;
  while(e!=0){
    input.push_back(e);
    cin>>e;
  }
  
  DynamicProgram(0,0);
  
  cout<<DP[0][0];
}