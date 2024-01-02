import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[] inOrder;
    static int[] postOrder;
    static int[] index;//inOrder의 원소가 위차한 인덱스를 저장하는 배열

    static void printPostorder(int sPost, int ePost, int sIn, int eIn) {
        if (sPost > ePost) return;
        System.out.print(postOrder[ePost] + " ");
        int divide = index[postOrder[ePost]];
        printPostorder(sPost, ePost - 1 - (eIn - divide), sIn, divide - 1);
        printPostorder(sPost + divide - sIn, ePost - 1, divide + 1, eIn);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(bf.readLine());
        inOrder = new int[n];
        postOrder = new int[n];
        index = new int[n + 1];
        StringTokenizer st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++) {
            inOrder[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++) {
            postOrder[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; i++) {
            index[inOrder[i]] = i;
        }
        printPostorder(0, n - 1, 0, n - 1);
    }
}