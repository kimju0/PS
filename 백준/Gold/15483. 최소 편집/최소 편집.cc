#include <iostream>

using namespace std;
string A, B;
int DP[1001][1001];

int main() {
    cin >> A >> B;
    for (int i = 1; i <= A.size(); i++)
        DP[0][i] = i;
    for (int i = 1; i <= B.size(); i++)
        DP[i][0] = i;
    for (int i = 1; i <= B.size(); i++) {
        for (int j = 1; j <= A.size(); j++) {
            DP[i][j] = min(DP[i - 1][j], min(DP[i][j - 1], DP[i - 1][j - 1])) + 1;
            if (A[j - 1] == B[i - 1])
                DP[i][j] = min(DP[i][j], DP[i - 1][j - 1]);
        }
    }
    cout << DP[B.size()][A.size()];
}