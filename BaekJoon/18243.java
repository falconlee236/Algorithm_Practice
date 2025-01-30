package BaekJoon;
import java.util.*;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[][] dp = new int[N + 1][N + 1];
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++) dp[i][j] = 0xFFFFF;
        }
        while (K-->0){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            dp[a][b] = 1;
            dp[b][a] = 1;
        }
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++) dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if (dp[i][j] > 6){
                    System.out.println("Big World!");
                    return;
                }
            }
        }
        System.out.println("Small World!");
    }    
}