import java.util.Scanner;

public class Main {
    static int n;
    static int[] inOrder;
    static int[] postOrder;
    static int[] index;//inOrder의 원소가 위차한 인덱스를 저장하는 배열

    static void printPostorder(int sPost, int ePost, int sIn, int eIn) {
        //System.out.println("sPost: "+sPost+" ePost: "+ePost+" sIn: "+sIn+" eIn: "+eIn);
        if (sPost > ePost) return;
        System.out.print(postOrder[ePost] + " ");
        int divide = index[postOrder[ePost]];
        printPostorder(sPost, ePost - 1 - (eIn - divide), sIn, divide - 1);
        printPostorder(sPost + divide - sIn, ePost - 1, divide + 1, eIn);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        inOrder = new int[n];
        postOrder = new int[n];
        index = new int[n + 1];
        for (int i = 0; i < n; i++) {
            inOrder[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            postOrder[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            index[inOrder[i]] = i;
        }
        printPostorder(0, n - 1, 0, n - 1);
    }
}