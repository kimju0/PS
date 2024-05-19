#include <iostream>
#include <algorithm>

using namespace std;

int N, K, L, board[101][101][2], curTime = 0;
int dir = 0, dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
pair<int, int> head = {1, 1}, tail = {1, 1};

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        board[y][x][0] = 2;
    }
    cin >> L;
    board[1][1][0] = 1;
    board[1][1][1] = dir;
    for (int i = 0; i < L + 1; i++) {
        int x = 20000;
        char c;
        if (i < L)cin >> x >> c;
        while (curTime < x) {
            curTime++;
            int ny = head.first + dy[dir], nx = head.second + dx[dir];
            if (ny < 1 || ny > N || nx < 1 || nx > N || board[ny][nx][0] == 1) {
                cout << curTime;
                return 0;
            }
            head = {ny, nx};
            if (board[ny][nx][0] == 0) {
                board[tail.first][tail.second][0] = 0;
                tail = {tail.first + dy[board[tail.first][tail.second][1]],
                        tail.second + dx[board[tail.first][tail.second][1]]};
            }
            board[ny][nx][0] = 1;
            board[ny][nx][1] = dir;
        }
        if (c == 'L') dir = (dir + 3) % 4;
        else dir = (dir + 1) % 4;
        board[head.first][head.second][1] = dir;
    }
}