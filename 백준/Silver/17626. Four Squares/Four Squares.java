import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        int[][] DP = new int[224][50001];
        n=scanner.nextInt();
        int row=1;
        for(int i=1;i<=n;i++){
            if(i*i>n){
                row = i-1;
                break;
            }
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=n;j++){
                if(i==1){
                    DP[i][j]=j;
                }
                else{
                    if(j-i*i>=0){
                        DP[i][j]=Math.min(DP[i-1][j],DP[i][j-i*i]+1);
                    }
                    else{
                        DP[i][j]=DP[i-1][j];
                    }
                }
            }
        }
        System.out.println(DP[row][n]);
    }
}