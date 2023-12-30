#include <stdio.h>

int T, N;

int square() {
    if (N <= 0) {
        return 1;
    }
    long long ret = 2, extra = 1;
    while (N != 1) {
        if (N % 2 == 0) {
            N /= 2;
            ret *= ret;
        } else {
            N--;
            extra *= ret;
        }
        ret %= 1000000007;
        extra %= 1000000007;
    }
    return (ret * extra) % 1000000007;
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        N -= 2;
        printf("%d\n", square());
    }
}
