import java.util.Scanner;

public class Main {
    static int[][] board;
    static int resWhite = 0;
    static int resBlack = 0;
    static void recursiveCut(int x, int y, int size){
        boolean is0Exist = false, is1Exist = false;
        boolean haveToCut = false;
        for(int i = x; i < x + size; i++){
            for(int j = y; j < y + size; j++){
                if(board[i][j] == 0){
                    is0Exist = true;
                }
                else{
                    is1Exist = true;
                }
            }
            if(is0Exist && is1Exist){
                haveToCut = true;
                break;
            }
        }
        if(haveToCut){
            recursiveCut(x, y, size / 2);
            recursiveCut(x + size / 2, y, size / 2);
            recursiveCut(x, y + size / 2, size / 2);
            recursiveCut(x + size / 2, y + size / 2, size / 2);
        }
        else{
            if(is0Exist){
                resWhite++;
            }
            else{
                resBlack++;
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        board = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        recursiveCut(0, 0, N);
        System.out.println(resWhite);
        System.out.println(resBlack);
    }
}