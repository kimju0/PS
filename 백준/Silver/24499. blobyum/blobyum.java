import java.util.Scanner;

public class Main {
    static int res, N, K;
    static int[] arr;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        for (int i = 1; i < N; i++) arr[i] += arr[i - 1];

        res = arr[K - 1];
        for (int i = 1; i < N; i++) {
            if (res < arr[(i + K) % N] - arr[i]) res = arr[(i + K) % N] - arr[i];
            if ((i + K) % N < i)
                if (res < arr[N - 1] - arr[i] + arr[(i + K) % N]) res = arr[N - 1] - arr[i] + arr[(i + K) % N];
        }
        System.out.println(res);
    }
}