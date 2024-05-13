#include <iostream>

using namespace std;


int main() {
    int N,flag;
    double matrix[6][7];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        flag=-1;
        for(int j=i;j<N;j++){
            if(matrix[j][j]!=0){
                flag=j;
                break;
            }
        }
        for(int j=0;j<=N;j++){
            swap(matrix[i][j],matrix[flag][j]);
        }
        for(int j=N;j>=i;j--){
            matrix[i][j]/=matrix[i][i];
        }
        for(int j=0;j<N;j++){
            if(j==i) continue;
            for(int k=N;k>=i;k--){
                matrix[j][k]-=matrix[j][i]*matrix[i][k];
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<matrix[i][N]<<' ';
    }
}