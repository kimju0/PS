#include <iostream>
#include <stack>

using namespace std;

int T,n,selectt[100001],res[100001],popped,setNum,out,nextt;
//res: 0)미정 -1)어느 팀에도 속하지 못한 원소 >0)숫자에 해당하는 집합에 포함되는 원소
bool isDefined[100001];//탐색 과정에 있는지 확인하기 위한 변수
stack<int> s;

void DFS(int target){
  isDefined[target]=true;
  s.push(target);
  while(!s.empty()){
    popped=s.top();
    nextt=selectt[popped];
    if(isDefined[nextt]==true&&res[nextt]==0){//사이클이 생긴 경우
      int untill=nextt,flag=setNum;
      while(!s.empty()){
        int p=s.top();
        s.pop();
        res[p]=flag;
        if(p==untill) flag=-1;
      }
      setNum++;
    }
    else if(isDefined[nextt]==true&&res[nextt]!=0){//이미 구성된 팀원을 선택한 경우
      while(!s.empty()){
        int p=s.top();
        s.pop();
        res[p]=-1;
      }
    }
    else{
      isDefined[nextt]=true;
      s.push(nextt);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>n;
    out=0;
    s=stack<int>();
    setNum=1;
    for(int i=1;i<=n;i++){
      cin>>selectt[i];
      isDefined[i]=false;
      res[i]=0;
    }
    
    for(int i=1;i<=n;i++){
      if(isDefined[i]==true) continue;
      DFS(i);
    }
    for(int i=1;i<=n;i++){
      if(res[i]==-1)out++;
    }
    cout<<out<<endl;
  }
}