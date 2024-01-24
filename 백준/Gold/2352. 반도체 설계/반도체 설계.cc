#include <iostream>

using namespace std;
int n, arr[40000], LIS[40000], tail = 0;

int lower_bound(int value) {
    int s = 0, e = tail - 1, m;
    while (s < e) {
        m = (s + e) / 2;
        if (LIS[m] < value) s = m + 1;
        else e = m;
    }
    return e;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    LIS[tail++] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > LIS[tail - 1]) LIS[tail++] = arr[i];
        else {
            LIS[lower_bound(arr[i])] = arr[i];
        }
    }
    cout << tail;
}