#include <iostream>

using namespace std;
int score[5], res;

int main() {
    for (int &i: score) {
        cin >> i;
        if (i < 40)
            i = 40;
        res += i;
    }
    cout << res / 5;
}