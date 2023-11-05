#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct PAIR {
	int A, B;
}PAIR;
PAIR pair[100000];
int N, LIS[100000], tail, res[100000],flag[100000];
int compare(const void* f, const void* s) { return ((PAIR*)f)->A - ((PAIR*)s)->A;}
int lowerbound(int t) {
	int s=0, e=tail-1,m;
	while (s < e) {
		m = (s + e) / 2;
		if (pair[LIS[m]].B < t)s = m + 1;
		else e = m;
	}
	return s;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &(pair[i].A), &(pair[i].B));
	}
	qsort(pair, N, sizeof(PAIR), compare);
	for (int i = 0; i < N; i++) {
		if (tail == 0 || pair[LIS[tail - 1]].B < pair[i].B) {
			if (tail == 0)res[i] = -1;
			else res[i] = LIS[tail - 1];
			LIS[tail++] = i;
		}
		else {
			int ind = lowerbound(pair[i].B);
			if (ind == 0)res[i] = -1;
			else res[i] = LIS[ind - 1];
			LIS[ind] = i;
		}
	}
	printf("%d\n", N - tail);
	int cur = LIS[tail - 1];
	while (cur >= 0) {
		flag[cur] = 1;
		cur = res[cur];
	}
	for (int i = 0; i < N; i++) {
		if (flag[i] == 1)continue;
		printf("%d\n", pair[i].A);
	}
}