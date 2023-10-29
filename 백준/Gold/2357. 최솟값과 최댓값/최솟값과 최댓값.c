#include <stdio.h>
#define MAX(x,y) (x)<(y)?(y):(x)
#define MIN(x,y) (x)<(y)?(x):(y)
int N, M, depth,leap=1;//루트노드 깊이는 0,최대 깊이는 16.xxx=17
int min_segment_tree[262144];//깊이가 17인 이진트리의 노드 갯수+1
int max_segment_tree[262144];
int Prefix_Min(int s,int e) {
    int ret = 1000000000;
    while (s<=e) {
        ret = MIN(min_segment_tree[s], MIN(min_segment_tree[e], ret));
        if (s / 2 == (s + 1) / 2)s /= 2;
        else s = s / 2 + 1;
        if (e / 2 == (e - 1) / 2)e /= 2;
        else e = e / 2 - 1;
    }
    return ret;
}
int Prefix_Max(int s, int e) {
    int ret = 0;
    while (s <= e) {
        ret = MAX(max_segment_tree[s], MAX(max_segment_tree[e], ret));
        if (s / 2 == (s + 1) / 2)s /= 2;
        else s = s / 2 + 1;
        if (e / 2 == (e - 1) / 2)e /= 2;
        else e = e / 2 - 1;
    }
    return ret;
}
int main() {
    for (int i = 0; i < 262144; i++)min_segment_tree[i] = 1000000000;
    scanf("%d%d", &N, &M);
    while (leap < N)depth++, leap *= 2;
    int start = leap;//이 인덱스부터 N개 넣으면 됌
    for (int i = 0; i < N; i++) {
        scanf("%d", &min_segment_tree[start+i]);
        max_segment_tree[start + i] = min_segment_tree[start + i];
    }
    for (int i = 2*start-1; i > 0; i--) {
        min_segment_tree[i / 2] = MIN(min_segment_tree[i], min_segment_tree[i / 2]);
        max_segment_tree[i / 2] = MAX(max_segment_tree[i], max_segment_tree[i / 2]);
    }
    for (int i = 0; i < M; i++) {
        int s, e;
        scanf("%d%d", &s, &e);
        printf("%d %d\n", Prefix_Min(leap-1+s, leap - 1 + e), Prefix_Max(leap - 1 + s, leap - 1 + e));
    }
}