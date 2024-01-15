#include <iostream>

using namespace std;
int N;
string curArr, targetArr;

int foo(string curArr, string targetArr) {
    int ret = 0;
    for (int i = 1; i < N; i++) {
        if (curArr[i - 1] != targetArr[i - 1]) {
            ret++;
            curArr[i - 1] = curArr[i - 1] == '0' ? '1' : '0';
            curArr[i] = curArr[i] == '0' ? '1' : '0';
            if (i != N - 1) curArr[i + 1] = curArr[i + 1] == '0' ? '1' : '0';
        }
    }
    if (curArr[N - 1] != targetArr[N - 1]) return 100001;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    curArr.reserve(100000);
    targetArr.reserve(100000);
    cin >> N >> curArr >> targetArr;
    int res = foo(curArr, targetArr);
    curArr[0] = curArr[0] == '0' ? '1' : '0';
    curArr[1] = curArr[1] == '0' ? '1' : '0';
    res = min(res, foo(curArr, targetArr) + 1);
    if (res == 100001) res = -1;
    cout << res << endl;
}