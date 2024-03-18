#include <vector>
#include <algorithm>

using namespace std;

int QuickSelect(vector<int> &a,int i,int j,int k){
    int p=a[rand()%(j-i)+i];
    int s=i-1,e=j;
    for(int n=i;n<e;n++){
        if(a[n]<p) swap(a[n],a[++s]);
        if(a[n]>p) {swap(a[n],a[--e]); n--;}
    }
    if(k>=e) return QuickSelect(a,e,j,k);
    if(k<=s) return QuickSelect(a,i,s+1,k);
    return p;
}

int kth(vector<int> &a, int k) {
	return QuickSelect(a,0,a.size(),k-1);
}
