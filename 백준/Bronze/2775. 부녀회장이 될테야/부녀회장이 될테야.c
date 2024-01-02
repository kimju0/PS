#include <stdio.h>
int recursion(int k, int n);
int main(void) {
	int T, k, n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &k, &n);
		printf("%d\n",recursion(k, n));
	}
}

int recursion(int k, int n) {
	if (n == 1) {
		return 1;
	}
	else if (k == 0) {
		return n;
	}
	return recursion(k, n - 1) + recursion(k - 1, n);
}