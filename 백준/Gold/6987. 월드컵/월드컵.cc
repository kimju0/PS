#include <iostream>
using namespace std;
int inp[4][6][3], res[4];
int st[6][3];
void ch() {
    bool flag;
    for (int i = 0; i < 4; i++) {
        flag = true;
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                if (inp[i][j][k] != st[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) res[i] = 1;
    }
}
void bt(int s, int e) {
    if (s == 6) {
        ch();
        return;
    }
    if (e == 6) {
        bt(s + 1, s + 2);
        return;
    }
    st[s][0]++, st[e][2]++;
    bt(s, e + 1);
    st[s][0]--, st[e][2]--;
    st[e][0]++, st[s][2]++;
    bt(s, e + 1);
    st[e][0]--, st[s][2]--;
    st[s][1]++, st[e][1]++;
    bt(s, e + 1);
    st[s][1]--, st[e][1]--;
}
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> inp[i][j][k];
            }
        }
    }
    bt(0, 1);
    for (int r: res) {
        cout << r << ' ';
    }
}