#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n, arr[1000];
long long sum=1;
int compare(const void*first,const void*second) {
	if (*(int*)first > *(int*)second)return 1;
	else if (*(int*)first < *(int*)second)return -1;
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);
	if (arr[0] != 1) {
		printf("%d", 1);
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (arr[i] > sum + 1)break;
		sum += arr[i];
	}
	printf("%d", sum + 1);
}