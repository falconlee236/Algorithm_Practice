package BaekJoon;
import java.io.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] lst = br.readLine().split(" ");
        int N = Integer.parseInt(lst[0]);
        int M = Integer.parseInt(lst[1]);
        long[][][] dp = new long[N + 1][M + 1][3];
        for(int i = 1; i <= M; i++) dp[1][i][0] = 1;
        long DIV = 998_244_353, ans = 0;
        for(int i = 2; i <= N; i++){
            for(int j = 1; j <= M; j++){
                dp[i][j][0] += (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2]) % DIV;
                for(int k = 1; k < j; k++) {
                    dp[i][j][1] += dp[i - 1][k][0] + dp[i - 1][k][1] + dp[i - 1][k][2];
                    dp[i][j][1] %= DIV;
                }
                for(int k = j + 1; k <= M; k++) {
                    dp[i][j][2] += dp[i - 1][k][0] + dp[i - 1][k][2];
                    dp[i][j][2] %= DIV;
                }
            }
        }
        for(int i = 1; i <= M; i++) {
            ans += dp[N][i][0] + dp[N][i][1] + dp[N][i][2];
            ans %= DIV;
        }
        System.out.println(ans);
    }
}