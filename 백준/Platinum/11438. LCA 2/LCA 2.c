#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct adj {
    int NODEnum;
    struct adj* link;
}adj;
adj tree[100001];
int N, M, depth[100001], maxSQUARE,PARENT[100001][17];//lg(100000)=16.xxx
void appendTREE(int s, int e) {
    adj* neww = (adj*)malloc(sizeof(adj));
    neww->NODEnum = e;
    neww->link = tree[s].link;
    tree[s].link = neww;
}
void makePARENT() {
    int queue[100000], head = 0, tail = 0;
    queue[tail++] = 1;
    PARENT[1][0] = -1, depth[1] = 0;
    while (head != tail) {
        int cur = queue[head++];
        adj* curNODE = &tree[cur];
        while (curNODE->link != NULL) {
            if (PARENT[curNODE->link->NODEnum][0] == 0) {
                queue[tail++] = curNODE->link->NODEnum;
                PARENT[curNODE->link->NODEnum][0] = cur;
                depth[curNODE->link->NODEnum] = depth[cur] + 1;
                if (maxSQUARE < depth[curNODE->link->NODEnum])maxSQUARE = depth[curNODE->link->NODEnum];
            }
            curNODE = curNODE->link;
        }
    }
    maxSQUARE = (int)log2(maxSQUARE);
    for (int k = 1; k <= maxSQUARE; k++) {
        for (int n = 1; n <= N; n++) {
            if ((int)log2(depth[n])<k)continue;
            PARENT[n][k] = PARENT[PARENT[n][k - 1]][k - 1];
        }
    }
}
int LCA(int v1, int v2) {
    int cur ,to;
    if (depth[v1] > depth[v2]) cur = v1, to = v2;
    else cur = v2, to = v1;
    //cur이 더 낮은 위치에 있는 노드이고 이를 to의 위치까지 올리기
    while (depth[cur] != depth[to]) {
        int d=0;
        for (int i = 0; i <= maxSQUARE; i++) {
            if (log2(depth[cur]) < i) break;
            if (depth[PARENT[cur][i]] >= depth[to])d = i;//else break로 시간 줄일 수 있을 듯
        }
        cur = PARENT[cur][d];
    }

    //두 노드의 공통조상 찾기
    while (cur != to) {
        int i = 0;
        while (PARENT[ cur][i+1] !=PARENT[ to][i+1] && log2(depth[cur]) >= i) {
            i++;
        }
        cur = PARENT[cur][i];
        to = PARENT[to][i];
    }
    return cur;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        appendTREE(v1, v2);
        appendTREE(v2, v1);
    }
    makePARENT();
    /*
    for (int k = 0; k <= maxSQUARE; k++) {
        for (int i = 1; i <= N; i++)printf("%d ", PARENT[i][k]);
        printf("\n");
    }
    */
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        printf("%d\n", LCA(v1, v2));
    }
}