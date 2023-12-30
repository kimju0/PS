import java.util.Scanner;

class matrix {
    int[][] matrix;
    int N;

    matrix(int N) {
        this.N = N;
        matrix = new int[N][N];
    }
    void getMatrix(int N, Scanner sc) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
    }

    void multiply(matrix a, matrix b) {
        int[][] temp = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                int sum = 0;
                for (int j = 0; j < N; j++) {
                    sum += (a.matrix[i][j] * b.matrix[j][k]) % 1000;
                }
                temp[i][k] = sum % 1000;
            }
        }
        matrix = temp;
    }
    void makeIdentity() {
        for (int i = 0; i < N; i++) {
            matrix[i][i] = 1;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int N;
        long B;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        B = sc.nextLong();
        matrix ret = new matrix(N);
        ret.getMatrix(N, sc);
        matrix extra = new matrix(N);
        extra.makeIdentity();
        while (B > 1) {
            if (B % 2 == 1) {
                extra.multiply(extra, ret);
            }
            ret.multiply(ret, ret);
            B /= 2;
        }
        ret.multiply(ret, extra);
        for (int[] i : ret.matrix) {
            for (int j : i) {
                System.out.print(j % 1000 + " ");
            }
            System.out.println();
        }
    }
}