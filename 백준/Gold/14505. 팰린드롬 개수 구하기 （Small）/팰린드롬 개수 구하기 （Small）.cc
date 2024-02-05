#include <iostream>

using namespace std;
string S;
int DP[1000][1000];

int main() {
    cin >> S;
    for (int i = 0; i < S.size(); i++)
        DP[i][i] = 1;
    for (int i = 0; i < S.size() - 1; i++)
        DP[i][i + 1] = S[i] == S[i + 1] ? 3 : 2;
    for (int i = 2; i < S.size(); i++) {
        for (int j = 0; j < S.size() - i; j++) {
            DP[j][j + i] = (DP[j + 1][j + i] + DP[j][j + i - 1] + 1);
            if (S[j] != S[j + i]) {
                DP[j][j + i] -= (DP[j + 1][j + i - 1] + 1);
            }
        }
    }
    cout << DP[0][S.size() - 1];
}