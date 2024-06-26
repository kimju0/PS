#include <iostream>
#include <cassert>

using namespace std;
unsigned char DP[17001][4251];//a:00, d:01, m:10, c:11
enum method {
    a, d, m, c,
};
int dy[4] = {-1, 0, -1, -1}, dx[4] = {0, -1, -1, -1};
string in, out;

char converter(method meth) {
    if (meth == a)return 'a';
    else if (meth == d)return 'd';
    else if (meth == m)return 'm';
    else return 'c';
}

void set_dp(int y, int x, method m) {
    int shift = x % 4;
    //cout<<"DEBUG---"<<m<<endl;
    DP[y][x / 4] |= ((int)m << (shift*2));
}

method get_dp(int y, int x) {
    int mask = 3, shift = x % 4;
    //cout<<"DEBUG"<<(int)DP[y][x/4]<<endl;
    return static_cast<method>((DP[y][x / 4] >> (shift*2)) & mask);
}

void print(int y, int x) {
    assert(y>=0);
    assert(x>=0);
    if (y == 0 && x == 0)return;
    method meth = get_dp(y, x);
    int ny = y + dy[meth], nx = x + dx[meth];
    print(ny, nx);
    char c_meth = converter(meth), c_tar;
    if (meth == d)
        c_tar = in[x - 1];
    else
        c_tar = out[y - 1];
    cout << c_meth <<' '<< c_tar << endl;
}

int main() {

    int C[2][17001];
    cin >> in >> out;
    for (int i = 1; i <= in.size(); i++) {
        C[0][i] = i;
        set_dp(0, i, d);
    }
    for (int i = 1; i <= out.size(); i++) {
        C[1][0] = i;
        set_dp(i, 0, a);
        for (int j = 1; j <= in.size(); j++) {
            int cost = C[0][j] + 1;
            method meth = a;
            if (C[0][j - 1] + 1 < cost) {
                cost = C[0][j - 1] + 1;
                meth = m;
            }
            if (C[1][j - 1] + 1 < cost) {
                cost = C[1][j - 1] + 1;
                meth = d;
            }
            if (C[0][j - 1] < cost && in[j - 1] == out[i - 1]) {
                cost = C[0][j - 1];
                meth = c;
            }
            C[1][j] = cost;
            set_dp(i, j, meth);
        }

        //update array C
        for (int j = 0; j <= in.size(); j++) {
            C[0][j] = C[1][j];
        }
    }
    print(out.size(), in.size());
}