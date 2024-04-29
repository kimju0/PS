#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long> pq;
int T, K, inp;
long long res, X;
int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		res = 0;
		cin >> K;
		for (int k = 0; k < K; k++) {
			cin >> inp;
			pq.push(-inp);
		}
		while (pq.size() != 1) {
			X = -pq.top();
			pq.pop();
			X -= pq.top();
			pq.pop();
			res += X;
			pq.push(-X);
		}
		cout << res << endl;
		pq.pop();
	}
}