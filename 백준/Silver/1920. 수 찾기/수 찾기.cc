#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binary(vector<int>& a, int t)
{
    int low=0;
    int high=a.size()-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==t){
            printf("1\n");
            return;
        }
        else if(a[mid]>t) high=mid-1;
        else low=mid+1;
    }
    printf("0\n");
}
int main()
{
    int n,m,target;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    vector<int> num(m);
    for(int i=0; i<m; i++){
        scanf("%d", &num[i]);
    }
    sort(arr.begin(), arr.end());
    for(int i : num){
        if(i>arr[arr.size()-1] || i<arr[0]) cout<<"0"<<"\n";
        else binary(arr,i);
    }

    return 0;
}