#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> s;
long long N, res, inp[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> inp[i];
    for (int i = 0; i < N; i++) {
        if (s.empty())
            s.emplace(inp[i], 1);
        else if (inp[i] > s.top().first) {
            res++;
            i--;
            if (s.top().second == 1)
                s.pop();
            else
                s.top().second--;
        } else if (inp[i] == s.top().first) {
            res += s.top().second;
            s.top().second++;
            if (s.size() > 1)
                res++;
        } else {
            res++;
            s.emplace(inp[i], 1);
        }
    }
    cout << res;
}