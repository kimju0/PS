#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[500000],input;
bool binarySearch(int s, int e, int target){
  int m=(s+e)/2;
  while(s<=e){
    if(arr[m]==target)return true;
    else if(arr[m]>target) e=m-1;
    else s=m+1;
    m=(s+e)/2;
  }
  return false;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  sort(arr,arr + N);
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>input;
    cout<<(binarySearch(0,N-1,input)?1:0)<<" ";
  }
}