import java.util.Scanner;

public class Main {
    static int N;
    static int[][] board = new int[317][100001];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        int e = 1;
        while (e * e <= N) e++;
        e--;
        for (int i = 1; i <= e; i++) {
            for (int j = 1; j <= N; j++) {
                if (j == 1) board[i][j] = 1;
                else if (i == 1) board[i][j] = j;
                else {
                    if (i * i > j) {
                        board[i][j] = board[i - 1][j];
                    } else {
                        board[i][j] = Math.min(board[i - 1][j], board[i][j - i * i] + 1);
                    }
                }
            }
        }
        System.out.println(board[e][N]);
    }
}