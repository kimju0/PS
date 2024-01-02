import java.io.*;

class Main {
    static int N, res;
    static int[][] DP;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        DP = new int[10][N + 1];
        for (int i = 1; i < 10; i++) {
            DP[i][1] = 1;
        }
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 10; j++) {
                if (j == 0) {
                    DP[j][i] = DP[j + 1][i - 1];
                } else if (j == 9) {
                    DP[j][i] = DP[j - 1][i - 1];
                } else {
                    DP[j][i] = DP[j - 1][i - 1] + DP[j + 1][i - 1];
                }
                DP[j][i] %= 1000000000;
            }
        }
        res = 0;
        for (int i = 0; i < 10; i++) {
            res += (DP[i][N] % 1000000000);
            res %= 1000000000;
        }
        System.out.println(res);
    }
}