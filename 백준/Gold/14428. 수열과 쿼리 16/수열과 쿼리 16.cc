#include <iostream>
#include <unordered_map>
#include <memory.h>

using namespace std;

int height(int N) {
    int result = 0, total = 1;
    while (total < N) {
        total *= 2;
        result++;
    }
    return result;
}

void setSegmentTree(int *segmentTree, unordered_map<int, int> &map, int k) {
    int cur = (1 << k) - 1;
    while (cur > 0) {
        if (segmentTree[cur * 2] == 0 && segmentTree[cur * 2 + 1] == 0) {
            cur--;
            continue;
        } else if (segmentTree[cur * 2 + 1] == 0) {
            segmentTree[cur] = segmentTree[cur * 2];
            cur--;
            continue;
        }
        segmentTree[cur] =
                map[segmentTree[cur * 2]] > map[segmentTree[cur * 2 + 1]] ?
                segmentTree[cur * 2 + 1] : segmentTree[cur * 2];
        cur--;
    }
}

void updateSegmentTree(int *segmentTree, unordered_map<int, int> &map, int index, int value, int k) {
    int cur = (1 << k) + index - 1;
    map.erase(cur);
    map.insert(make_pair(cur, value));
    cur /= 2;
    while (cur > 0) {
        if (segmentTree[cur * 2] == 0 && segmentTree[cur * 2 + 1] == 0) {
            cur /= 2;
            continue;
        } else if (segmentTree[cur * 2 + 1] == 0) {
            segmentTree[cur] = segmentTree[cur * 2];
            cur /= 2;
            continue;
        }
        segmentTree[cur] =
                map[segmentTree[cur * 2]] > map[segmentTree[cur * 2 + 1]] ?
                segmentTree[cur * 2 + 1] : segmentTree[cur * 2];
        cur /= 2;
    }
}

int getSegmentTree(const int *segmentTree, unordered_map<int, int> &map, int s, int e, int k) {
    s = (1 << k) + s - 1;
    e = (1 << k) + e - 1;
    int ret = s;
    while (s <= e) {
        if (s % 2 == 1) {
            if (segmentTree[s] != 0)
                ret = map[ret] > map[segmentTree[s]] ? segmentTree[s] : ret;
            if (map[ret] == map[segmentTree[s]])
                ret = ret > segmentTree[s] ? segmentTree[s] : ret;
            s++;
        }
        if (e % 2 == 0) {
            if (segmentTree[e] != 0)
                ret = map[ret] > map[segmentTree[e]] ? segmentTree[e] : ret;
            if (map[ret] == map[segmentTree[e]])
                ret = ret > segmentTree[e] ? segmentTree[e] : ret;
            e--;
        }
        s /= 2;
        e /= 2;
    }
    ret = ret - (1 << k) + 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, k;
    unordered_map<int, int> map;
    cin >> N;
    k = height(N);
    int segmentTree[1 << (k + 1)];//the number of elements: 2^(k+1)
    memset(segmentTree, 0, sizeof(segmentTree));
    for (int i = 0; i < N; i++) {
        int index = (1 << k) + i;
        int value;
        cin >> value;
        segmentTree[index] = index;
        map.insert(make_pair(index, value));
    }
    setSegmentTree(segmentTree, map, k);
    cin >> M;
    for (int m = 0; m < M; m++) {
        int stmt, i, j;
        cin >> stmt >> i >> j;
        if (stmt == 1) {
            updateSegmentTree(segmentTree, map, i, j, k);
        } else {
            cout << getSegmentTree(segmentTree, map, i, j, k) << "\n";
        }
    }
}