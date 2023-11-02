#include <stdio.h>
#include <stdlib.h>
int n, a[1000], s=1;
int c(const void*f,const void*s){return *(int*)f-*(int*)s;}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	qsort(a, n, 4, c);
	if (a[0] != 1) {
		printf("%d", 1);
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] > s + 1)break;
		s += a[i];
	}
	printf("%d", s + 1);
}