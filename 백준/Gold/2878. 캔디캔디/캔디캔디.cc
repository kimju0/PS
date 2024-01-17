#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long M, N;
    unsigned long long arr[100001];
    unsigned long long req, ind;
    bool flag = false;
    cin >> M >> N;
    ind = N + 1;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N + 1);
    while (M != 0) {
        ind = lower_bound(arr, arr + N + 1, arr[ind - 1]) - arr;
        req = (arr[ind] - arr[ind - 1]) * (N - (ind - 1));

        if (req <= M)
            M -= req;
        else {
            flag = true;
            for (int i = ind + 1; i <= N; i++) {
                arr[i] = arr[i - 1];
            }
            for (int i = ind; i <= N; i++) {
                arr[i] -= (M / (N - (ind - 1)));
            }
            M -= ((M / (N - (ind - 1))) * (N - (ind - 1)));
            break;
        }
    }
    if (!flag) {
        ind = lower_bound(arr, arr + N + 1, arr[ind - 1]) - arr;
        for (int i = ind + 1; i <= N; i++) {
            arr[i] = arr[i - 1];
        }
    }
    unsigned long long result = 0;
    for (int i = 1; i <= N; i++) {
        if (M > 0 && i >= ind) {
            arr[i]--;
            M--;
        }
        result += (arr[i] * arr[i]);
    }
    assert(M == 0);
    cout << result;
}