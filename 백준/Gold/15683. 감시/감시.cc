#include <iostream>
#include <cassert>

using namespace std;
int N, M, board[8][8];
int CCTV[8][2], tail;
int blank, res;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
//0: 우, 1: 하, 2: 좌, 3:상
int dirOfEachCCTV[6][4] = {{},
                           {0, -1, -1, -1},
                           {0, 2,  -1, -1},
                           {0, 3,  -1, -1},
                           {0, 3,  2,  -1},
                           {0, 1,  2,  3}};

int check_linear(int dir, int y, int x, int curCCTV, bool reverse) {
    int ret = 0;
    while (true) {
        y += dy[dir], x += dx[dir];
        if (y < 0 || y >= N || x < 0 || x >= M) break;
        if (board[y][x] == 6)break;//벽

        if (reverse) {
            assert(board[y][x] != 0);
            if (board[y][x] != -(curCCTV + 1)) continue;
            board[y][x] = 0;
        } else {
            if (board[y][x] != 0)continue;
            board[y][x] = -(curCCTV + 1);
            ret++;
        }
    }
    return ret;
}

void back_tracking(int curCCTV, int curRes) {
    if (curCCTV >= tail) {
        res = res < curRes ? curRes : res;
        return;
    }
    for (int i = 0; i < 4; i++) {//방향 전환
        int y = CCTV[curCCTV][0], x = CCTV[curCCTV][1];
        int checked = 0;
        for (int j = 0; j < 4; j++) {//CCTV 시야각
            int dir = dirOfEachCCTV[board[y][x]][j];
            if (dir == -1)break;
            dir += i;
            dir %= 4;
            checked += check_linear(dir, y, x, curCCTV, false);
        }

        back_tracking(curCCTV + 1, curRes + checked);

        for (int j = 0; j < 4; j++) {//CCTV 시야각
            int dir = dirOfEachCCTV[board[y][x]][j];
            if (dir == -1)break;
            dir += i;
            dir %= 4;
            check_linear(dir, y, x, curCCTV, true);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0)blank++;
            if (board[i][j] != 0 && board[i][j] != 6) {
                CCTV[tail][0] = i, CCTV[tail][1] = j;
                tail++;
            }
        }
    back_tracking(0, 0);
    cout << blank - res;
}