#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int in;
void recur(int s,int e){
    if(s>e) return;
    if(s==e){
        cout << v[s] << endl;
        return;
    }
    int mid=s+1;
    while(mid<=e&&v[mid]<v[s]) mid++;
    recur(s+1,mid-1);
    recur(mid,e);
    cout << v[s] << endl;
}
int main() {
    while (!cin.fail()) {
        cin >> in;
        v.push_back(in);
    }
    v.pop_back();
    recur(0,v.size()-1);
}