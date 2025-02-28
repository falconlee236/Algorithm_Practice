package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        int[][] dp = new int[N + 1][K + 1];
        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            if (i == 1){
                dp[1][a] = b;
                dp[1][c] = Math.max(dp[1][c], d);
            } else {
                for(int j = 0; j <= K; j++){
                    if (dp[i - 1][j] == 0) continue;
                    if (j + a <= K) dp[i][j + a] = Math.max(dp[i][j + a], dp[i - 1][j] + b);
                    if (j + c <= K) dp[i][j + c] = Math.max(dp[i][j + c], dp[i - 1][j] + d);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= K; i++) ans = Math.max(ans, dp[N][i]);
        System.out.println(ans);
    }
}