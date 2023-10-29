#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct adj {
    int NODEnum, w;
    struct adj* link;
}adj;
adj tree[100001];
int N, M, depth[100001], maxSQUARE, PARENT[100001][17];//lg(100000)=16.xxx
long long  cost[100001][17];
void appendTREE(int s, int e, int w) {
    adj* neww = (adj*)malloc(sizeof(adj));
    neww->NODEnum = e;
    neww->link = tree[s].link;
    neww->w = w;
    tree[s].link = neww;
}
void makePARENT() {
    int queue[100000], head = 0, tail = 0;
    queue[tail++] = 1;
    PARENT[1][0] = -1, depth[1] = 0;
    cost[1][0] = 0;
    while (head != tail) {
        int cur = queue[head++];
        adj* curNODE = &tree[cur];
        while (curNODE->link != NULL) {
            if (PARENT[curNODE->link->NODEnum][0] == 0) {
                queue[tail++] = curNODE->link->NODEnum;
                PARENT[curNODE->link->NODEnum][0] = cur;
                cost[curNODE->link->NODEnum][0] = curNODE->link->w;
                depth[curNODE->link->NODEnum] = depth[cur] + 1;
                if (maxSQUARE < depth[curNODE->link->NODEnum])maxSQUARE = depth[curNODE->link->NODEnum];
            }
            curNODE = curNODE->link;
        }
    }
    maxSQUARE = (int)log2(maxSQUARE);
    for (int k = 1; k <= maxSQUARE; k++) {
        for (int n = 1; n <= N; n++) {
            if ((int)log2(depth[n]) < k)continue;
            PARENT[n][k] = PARENT[PARENT[n][k - 1]][k - 1];
            cost[n][k] = cost[PARENT[n][k - 1]][k - 1] + cost[n][k - 1];
        }
    }
}
long long LCA(int v1, int v2, int k) {
    long long w = 0;
    int cur, to;
    if (depth[v1] > depth[v2]) cur = v1, to = v2;
    else cur = v2, to = v1;
    //cur이 더 낮은 위치에 있는 노드이고 이를 to의 위치까지 올리기
    while (depth[cur] != depth[to]) {
        int d = 0;
        for (int i = 0; i <= maxSQUARE; i++) {
            if (log2(depth[cur]) < i) break;
            if (depth[PARENT[cur][i]] >= depth[to])d = i;//else break로 시간 줄일 수 있을 듯
        }
        w += cost[cur][d];
        cur = PARENT[cur][d];
    }

    //두 노드의 공통조상 찾기
    while (cur != to) {
        int i = 0;
        while (PARENT[cur][i + 1] != PARENT[to][i + 1] && log2(depth[cur]) >= i+1) {
            i++;
        }
        w += cost[cur][i];
        w += cost[to][i];
        cur = PARENT[cur][i];
        to = PARENT[to][i];
    }
    if (k == -1) return w;
}
int secLCA(int v1, int v2, int k) {
    int start=v1,goal = v2;
    k -= 1;
    int cur, to;
    if (depth[v1] > depth[v2]) cur = v1, to = v2;
    else cur = v2, to = v1;
    int temp_to = to, temp_cur = cur;
    int first_count = 0;//낮은 위치에 있는 노드와 높은 위치와의 차이
    //cur이 더 낮은 위치에 있는 노드이고 이를 to의 위치까지 올리기
    while (depth[cur] != depth[to] ) {
        int d = 0;
        for (int i = 0; i <= maxSQUARE; i++) {
            if (log2(depth[cur]) < i ) break;
            if (depth[PARENT[cur][i]] >= depth[to])d = i;//else break로 시간 줄일 수 있을 듯
        }
        //if (k - pow(2, d) < 0)continue;
        //k -= pow(2, d);
        cur = PARENT[cur][d];
        first_count += pow(2, d);
    }

    //if (k == 0)return cur;
    //위 조건문 통과한다는건 k가 아직 0이 아니고 두 정점이 같은 위치

    //두 노드의 공통조상 찾기
    int second_count = 0;//공통조상까지 올라가는데 올라간 횟수
    while (cur != to) {
        int i = 0;
        while (PARENT[cur][i + 1] != PARENT[to][i + 1] && log2(depth[cur]) >= i) {
            i++;
        }
        cur = PARENT[cur][i];
        to = PARENT[to][i];
        second_count += pow(2, i);
    }

    //start에서 goal까지 가야함
    if (start == temp_cur) {//start 노드가 더 낮은 높이에 있는 경우
        if (first_count + second_count > k) {//head와 start 사이에 k번째 노드 존재
            temp_cur = start;

            while (k != 0) {
                int d = 0;
                for (int i = 0; i <= log2(temp_cur); i++) {
                    if (k - pow(2, i) < 0)break;
                    if (depth[PARENT[temp_cur][i]] >= depth[cur])d = i;
                }
                temp_cur = PARENT[temp_cur][d];
                k -= pow(2, d);
            }
            return temp_cur;
        }
        else if (first_count + second_count < k) {//head와 goal 사이에 k번째 노드 존재
            temp_to = goal;
            k = 2 * second_count + first_count - k;
            while (k != 0) {
                int d = 0;
                for (int i = 0; i <= log2(temp_to); i++) {
                    if (k - pow(2, i) < 0)break;
                    if (depth[PARENT[temp_to][i]] >= depth[to])d = i;
                }
                temp_to = PARENT[temp_to][d];
                k -= pow(2, d);
            }
            return temp_to;
        }
        else return cur;
    }
    else {//시작노드가 더 높거나 같은 높이에 있음
        if (second_count > k) {//head와 start 사이에 k번째 노드 존재
            temp_cur = start;
            while (k != 0) {
                int d = 0;
                for (int i = 0; i <= log2(temp_cur); i++) {
                    if (k - pow(2, i) < 0)break;
                    if (depth[PARENT[temp_cur][i]] >= depth[cur])d = i;
                }
                temp_cur = PARENT[temp_cur][d];
                k -= pow(2, d);
            }
            return temp_cur;
        }
        else if (second_count < k) {//head와 goal 사이에 k번째 노드 존재
            temp_to = goal;
            k =2*second_count+first_count-k;
            while (k != 0) {
                int d = 0;
                for (int i = 0; i <= log2(temp_to); i++) {
                    if (k - pow(2, i) < 0)break;
                    if (depth[PARENT[temp_to][i]] >= depth[to])d = i;
                }
                temp_to = PARENT[temp_to][d];
                k -= pow(2, d);
            }
            return temp_to;
        }
        else return cur;
    }
}
int main() {
    //printf("%lld", 100000000000);
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int v1, v2, w;
        scanf("%d%d%d", &v1, &v2, &w);
        appendTREE(v1, v2, w);
        appendTREE(v2, v1, w);
    }
    makePARENT();

    //for (int k = 0; k <= maxSQUARE; k++) {
    //    for (int i = 1; i <= N; i++)printf("(%d, %d)  ", PARENT[i][k], cost[i][k]);
    //    printf("\n");
    //}

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int u, v, k, statement;
        scanf("%d", &statement);
        if (statement == 1) {
            scanf("%d%d", &u, &v);
            printf("%lld\n", LCA(u, v, -1));
        }
        else {
            scanf("%d%d%d", &u, &v, &k);
            printf("%d\n", secLCA(u, v, k));
        }
    }
}