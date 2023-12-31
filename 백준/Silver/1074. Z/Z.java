import java.util.Scanner;

public class Main {
    static int N, r, c;
    static int cnt = 0;

    static int pow(int e) {
        int res = 1;
        for (int i = 0; i < e; i++) {
            res *= 2;
        }
        return res;
    }

    static void Z(int curN, int curR, int curC) {
        if (curN == 0) {
            if (curR == r && curC == c) {
                System.out.println(cnt);
                System.exit(0);
            }
            cnt++;
            return;
        }
        int range = pow(curN - 1);

        if (curR <= r && r < curR + range && curC <= c && c < curC + range) {
            Z(curN - 1, curR, curC);
        } else if (curR <= r && r < curR + range && curC + range <= c && c < curC + pow(curN)) {
            cnt += range * range;
            Z(curN - 1, curR, curC + pow(curN - 1));
        } else if (curR + range <= r && r < curR + pow(curN) && curC <= c && c < curC + range) {
            cnt += range * range * 2;
            Z(curN - 1, curR + pow(curN - 1), curC);
        } else {
            cnt += range * range * 3;
            Z(curN - 1, curR + pow(curN - 1), curC + pow(curN - 1));
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();
        Z(N, 0, 0);
    }
}