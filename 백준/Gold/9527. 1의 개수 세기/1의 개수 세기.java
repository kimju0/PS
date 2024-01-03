import java.io.*;

class Main {
    static long A, B;
    static long log2_N;//최상위 비트만 1, log 함수가 호출됄 때만 초기화 됌
    static long simpleSum;//nC0-nCn까지의 합, sumCombiMulWei 함수가 호출됄 때만 초기화 됌

    static int log2(long N) {//N을 2진수로 표현하기 위한 비트 수
        int ret = 1;
        long temp = 1;
        log2_N = 1;
        while (temp < N) {
            temp = 2 * temp + 1;
            ret++;
            log2_N <<= 1;
        }
        return ret;
    }

    static long sumCombiMulWei(int N) {//N:4, 0000~1000까지 1의 합
        long ret = 1;
        long[][] DP = new long[N + 1][N + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) DP[i][j] = 1;
                else DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
            }
        }
        simpleSum = 0;
        for (int i = 0; i <= N; i++) {
            simpleSum += DP[N][i];
            ret += (DP[N][i] * i);
        }
        return ret;
    }

    static long sum_1(long N) {
        long ret = 0;
        int curBit = log2(N);
        int upperBit = 0;//현재 보고있는 비트 위에 몇 개의 비트가 1인지
        for (int i = 0; i < curBit; i++) {
            if ((N & log2_N) != 0) {
                ret += sumCombiMulWei(curBit - i - 1);
                ret += upperBit * simpleSum;
                upperBit++;
            }
            log2_N >>= 1;
        }
        return ret;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        A = Long.parseLong(input[0]);
        B = Long.parseLong(input[1]);
        //System.out.println(sum_1(A));
        System.out.println(sum_1(B) - sum_1(A - 1));
    }
}