import java.util.Scanner;

public class Main {
    static int res = -1;
    static int[][] board = new int[10][10];

    static void BackTracking(int cnt, int extraButton) {
        if (cnt == 10) {
            int tempRes = 0;
            int[][] temp = new int[10][10];
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    temp[i][j] = board[i][j];
                }
            }
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (temp[i - 1][j] == 0) {
                        tempRes++;
                        temp[i - 1][j] = 1;
                        temp[i][j] = temp[i][j] ^ 1;
                        if (j > 0) temp[i][j - 1] = temp[i][j - 1] ^ 1;
                        if (j < 9) temp[i][j + 1] = temp[i][j + 1] ^ 1;
                        if (i < 9) temp[i + 1][j] = temp[i + 1][j] ^ 1;
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                if (temp[9][i] == 0) return;
            }
            if (res == -1 || res > tempRes + extraButton) res = tempRes + extraButton;
            return;
        }
        BackTracking(cnt + 1, extraButton);

        board[0][cnt] = board[0][cnt] ^ 1;
        if (cnt > 0) board[0][cnt - 1] = board[0][cnt - 1] ^ 1;
        if (cnt < 9) board[0][cnt + 1] = board[0][cnt + 1] ^ 1;
        board[1][cnt] = board[1][cnt] ^ 1;

        BackTracking(cnt + 1, extraButton + 1);

        board[0][cnt] = board[0][cnt] ^ 1;
        if (cnt > 0) board[0][cnt - 1] = board[0][cnt - 1] ^ 1;
        if (cnt < 9) board[0][cnt + 1] = board[0][cnt + 1] ^ 1;
        board[1][cnt] = board[1][cnt] ^ 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            String str = sc.nextLine();
            for (int j = 0; j < 10; j++) {
                board[i][j] = str.charAt(j) == '#' ? 1 : 0;
            }
        }
        BackTracking(0, 0);
        System.out.println(res);
    }
}