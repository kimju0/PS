import java.io.*;

class Main {
    static int R, C, T;
    static int airCleanerTop = -1, airCleanerBottom = -1;
    static int[][] board;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    static void spreadDust() {
        int[][] tmp = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] > 0) {
                    int weight = board[i][j] / 5;
                    for (int k = 0; k < 4; k++) {
                        int nx = j + dx[k];
                        int ny = i + dy[k];
                        if (nx >= 0 && nx < C && ny >= 0 && ny < R && board[ny][nx] != -1) {
                            tmp[ny][nx] += weight;
                            board[i][j] -= weight;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] += tmp[i][j];
            }
        }
    }

    static void airCleaner() {
        int airX = 0, airY = airCleanerTop - 1;//-1에 있는건 공기청정기에 들어감
        while (airY > 0) {
            board[airY][airX] = board[airY - 1][airX];
            airY--;
        }
        while (airX < C - 1) {
            board[airY][airX] = board[airY][airX + 1];
            airX++;
        }
        while (airY < airCleanerTop) {
            board[airY][airX] = board[airY + 1][airX];
            airY++;
        }
        while (airX > 1) {
            board[airY][airX] = board[airY][airX - 1];
            airX--;
        }
        board[airCleanerTop][1] = 0;

        airX = 0;
        airY = airCleanerBottom + 1;
        while (airY < R - 1) {
            board[airY][airX] = board[airY + 1][airX];
            airY++;
        }
        while (airX < C - 1) {
            board[airY][airX] = board[airY][airX + 1];
            airX++;
        }
        while (airY > airCleanerBottom) {
            board[airY][airX] = board[airY - 1][airX];
            airY--;
        }
        while (airX > 1) {
            board[airY][airX] = board[airY][airX - 1];
            airX--;
        }
        board[airCleanerBottom][1] = 0;
    }


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        R = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);
        T = Integer.parseInt(input[2]);
        board = new int[R][C];
        for (int i = 0; i < R; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < C; j++) {
                board[i][j] = Integer.parseInt(input[j]);
                if (board[i][j] == -1) {
                    if (airCleanerTop == -1) {
                        airCleanerTop = i;
                    } else {
                        airCleanerBottom = i;
                    }
                }
            }
        }
        for (int i = 0; i < T; i++) {
            spreadDust();
            airCleaner();
        }
        int res = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                res += board[i][j];
            }
        }
        System.out.println(res + 2);
    }
}