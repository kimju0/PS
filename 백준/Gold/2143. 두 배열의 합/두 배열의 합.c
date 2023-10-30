#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int T, n, m;
long long res;
int arr_n[1000], arr_m[1000];
int sub_arr_n[500501], sub_arr_m[500501];
int tail_n,tail_m;
int compare(const void* first, const void* second) {
	if (*(int*)first < *(int*)second)return -1;
	else if (*(int*)first > *(int*)second)return 1;
	else return 0;
}
int upperBound(int target) {
	int s=0, e=tail_m-1, m;
	if (sub_arr_m[e] <= target)return e + 1;
	while (s < e) {
		m = (s + e) / 2;
		if (sub_arr_m[m] <= target)s = m + 1;
		else e = m;
	}
	return s;
}
int lowerBound(int target) {
	int s = 0, e = tail_m-1, m;
	if (sub_arr_m[e] < target)return e + 1;
	while (s < e) {
		m = (s + e) / 2;
		if (sub_arr_m[m] < target)s = m + 1;
		else e = m;
	}
	return s;
}
int main() {
	scanf("%d", &T);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &arr_n[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)scanf("%d", &arr_m[i]);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (j == i)sub_arr_n[tail_n] = arr_n[j];
			else sub_arr_n[tail_n] = sub_arr_n[tail_n - 1] + arr_n[j];
			tail_n++;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (j == i)sub_arr_m[tail_m] = arr_m[j];
			else sub_arr_m[tail_m] = sub_arr_m[tail_m - 1] + arr_m[j];
			tail_m++;
		}
	}
	qsort(sub_arr_m, tail_m, sizeof(int), compare);
	for (int i = 0; i < tail_n; i++) {
		res += upperBound(T-sub_arr_n[i]) - lowerBound(T-sub_arr_n[i]);
	}
	printf("%lld", res);
}