#include <iostream>
using namespace std;
int inp[4][6][3], res[4];
int state[6][3];
void check() {
    bool flag;
    for (int i = 0; i < 4; i++) {
        flag = true;
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                if (inp[i][j][k] != state[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) res[i] = 1;
    }
}
void backTracking(int s, int e) {
    if (s == 6) {
        check();
        return;
    }
    if (e == 6) {
        backTracking(s + 1, s + 2);
        return;
    }
    state[s][0]++, state[e][2]++;
    backTracking(s, e + 1);
    state[s][0]--, state[e][2]--;
    state[e][0]++, state[s][2]++;
    backTracking(s, e + 1);
    state[e][0]--, state[s][2]--;
    state[s][1]++, state[e][1]++;
    backTracking(s, e + 1);
    state[s][1]--, state[e][1]--;
}
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> inp[i][j][k];
            }
        }
    }
    backTracking(0, 1);
    for (int r: res) {
        cout << r << ' ';
    }
}