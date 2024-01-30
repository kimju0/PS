#include <iostream>

using namespace std;
int N;
int arr[500][2];
int DP[500][500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1];
    for (int i = 0; i < N - 1; i++) {
        DP[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
    }
    for (int i = 2; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            for (int k = 0; k < i; k++) {
                int temp = DP[j][j + k] + DP[j + k + 1][j + i] + arr[j][0] * arr[j + k][1] * arr[j + i][1];
                if (DP[j][j + i] == 0 || DP[j][j + i] > temp) DP[j][j + i] = temp;
            }
        }
    }
    cout << DP[0][N - 1] << endl;
}