import java.io.*;
import java.util.ArrayList;
import java.util.List;

class Main {
    static int T, n;
    static int[][] DP = new int[4][10001];

    public static void main(String args[]) throws IOException {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 10000; j++) {
                DP[i][j] = DP[i - 1][j];
                int temp = i;
                while (temp <= j) {
                    DP[i][j] += DP[i - 1][j - temp];
                    if (temp == j) DP[i][j]++;
                    temp += i;
                }
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            n = Integer.parseInt(br.readLine());
            System.out.println(DP[3][n]);
        }
    }
}