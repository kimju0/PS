#include<iostream>
#include<algorithm>
#include<cmath>
#include <limits>

typedef std::numeric_limits< double > dbl;

using namespace std;

int N,fence[17];
double DP[65535],res;
int state[16],tail;

double calc(int a,int b, int c){
  double ret,p;
  int t[3]={fence[a],fence[b],fence[c]};
  sort(t,t+3);
  if(t[2]>=t[0]+t[1]) return 0;
  p=(t[0]+t[1]+t[2])/2.;
  ret=sqrt(p*(p-t[0])*(p-t[1])*(p-t[2]));
  //if(t[0]==4&&t[1]==5&&t[2]==6)
    //cout<<"calc: "<<p<<endl;
  return ret;
}

int intToBit(){
  int ret=0;
  for(int i=0;i<tail;i++){
    ret+=1<<(state[i]-1);
  }
  return ret;
}

void DynamicProgram(){
  int cBit=intToBit();
  for(int i=0;i<tail;i++){
    for(int j=i+1;j<tail;j++){
      for(int k=j+1;k<tail;k++){
        int a=1<<(state[i]-1),b=1<<(state[j]-1),c=1<<(state[k]-1);
        if(DP[cBit]<DP[a|b|c]+DP[cBit^(a|b|c)])DP[cBit]=DP[a|b|c]+DP[cBit^(a|b|c)];
        if(res<DP[cBit])res=DP[cBit];
        if(cBit==0b1111110){
          //cout<<"NOW"<<endl;
        }
        if((a|b|c)==0b1110&&(cBit^(a|b|c))==0b1110000){
          //cout<<"NOW "<<a<<" "<<b<<" "<<c<<" "<<DP[a|b|c]<<" "<<DP[cBit^(a|b|c)]<<endl;
        }
      }
    }
  }
}

void backTracking(int target){
  if(tail==target){
    if(tail==3){
      int cBit=intToBit();
      DP[cBit]=calc(state[tail-1],state[tail-2],state[tail-3]);
      if(res<DP[cBit])res=DP[cBit];
      if(cBit==0b1110){
        //cout<<"HERE"<<DP[cBit]<<endl;
      }
    }
    else DynamicProgram();
    return;
  }
  int i=tail>0?state[tail-1]+1:1;
  for(;i<=N;i++){
    state[tail++]=i;
    backTracking(target);
    tail--;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N;
  for(int i=1;i<=N;i++){
    cin>>fence[i];
  }
  
  for(int i=1;i<=N/3;i++){
    backTracking(i*3);
  }
  
  cout.precision(dbl::max_digits10);
  cout<<fixed<<res;
}