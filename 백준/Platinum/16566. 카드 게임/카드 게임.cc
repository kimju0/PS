#include <stdlib.h>
#include <iostream>
using namespace std;
int N, M, K;
int chursoo[10000];
typedef struct C {
	int num, set;
}C;
C candidate[4000000];
int compare(const void* first, const void* second) {
	if (((C*)first)->num < ((C*)second)->num)return -1;
	else if (((C*)first)->num > ((C*)second)->num)return 1;
	else return 0;
}
int upperbound(int target) {
	int s = 0, e = M - 1, m;
	while (s < e) {
		m = (s + e) / 2;
		if (candidate[m].num <= target) s = m + 1;
		else e = m;
	}
	return s;
}
int d;
int find(int target) {
	if (candidate[target].set == 0)return target;
	d++;
	int recur = find(target + candidate[target].set);
	candidate[target].set = recur-target;
	return recur;
}
int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)cin >> candidate[i].num;
	for (int i = 0; i < K; i++)cin >> chursoo[i];
	qsort(candidate, M, sizeof(C), compare);
	int upper, res;
	for (int i = 0; i < K; i++) {
		upper = upperbound(chursoo[i]);
		d = 0;
		res = find(upper);
		candidate[res].set = 1;
		cout << candidate[res].num << '\n';
	}
}