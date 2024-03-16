#include <iostream>

using ll=long long;
using namespace std;

ll N, MOD=100000,DP[200][200];
string str;

int check(int i, int j) {
    if (str[i]=='('&&str[j]==')'||
        str[i]=='['&&str[j]==']'||
        str[i]=='{'&&str[j]=='}'||
        str[i]=='('&&str[j]=='?'||
        str[i]=='['&&str[j]=='?'||
        str[i]=='{'&&str[j]=='?'||
        str[i]=='?'&&str[j]==')'||
        str[i]=='?'&&str[j]==']'||
        str[i]=='?'&&str[j]=='}')
        return 1;
    else if (str[i]=='?'&&str[j]=='?')
        return 3;
    else return 0;
}

ll getDP(int s,int e){
    if(check(s,e)==0)return 0;
    if(s+1>e-1) return check(s,e);
    return (check(s,e)*DP[s+1][e-1]);
}

ll getSecDP(int s,int e){
  if(s>e)return 1;
  return DP[s][e];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>str;
    for (int i=0;i<N-1;i++){
        DP[i][i+1]=check(i,i+1);
    }
    for (int i=3;i<N;i+=2){
        for (int j=0;j<N-i;j++){
            for (int k=j+1;k<=i+j;k+=2){
                DP[j][i+j]+=(getDP(j,k)*getSecDP(k+1,i+j));
                if(DP[j][i+j]>MOD)
                    DP[j][i+j]=MOD+DP[j][i+j]%MOD;
            }
        }
    }
    if(DP[0][N-1]>MOD)
        printf("%05lld\n",DP[0][N-1]%MOD);
    else
        cout<<DP[0][N-1]<<endl;
}