package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), S = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int[][] dp = new int[N + 1][M + 1];
        dp[0][S] = 1;
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++){
            int num = Integer.parseInt(st.nextToken());
            for(int j = 0; j <= M; j++) {
                if (j - num >= 0) dp[i][j - num] = Math.max(dp[i][j - num], dp[i - 1][j] + 1);
                if (j + num <= M) dp[i][j + num] = Math.max(dp[i][j + num], dp[i - 1][j] + 1);
            }
        }
        int ans = -1;
        for(int i = 0; i <= M; i++) {
            if (dp[N][i] == N + 1) ans = Math.max(ans, i);
        }
        System.out.println(ans);
    }
}