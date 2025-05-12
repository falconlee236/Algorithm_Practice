package BaekJoon;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        long[][] dp = new long[100001][2]; // 1이 홀
        long div = 1_000_000_009;
        dp[1][1] = 1;
        dp[2][0] = 1;
        dp[2][1] = 1;
        dp[3][0] = 2;
        dp[3][1] = 2;
        for(int i = 4; i <= 100000; i++){
            dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % div;
            dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % div;
        }
        while (T-->0) {
            int N = Integer.parseInt(br.readLine());
            sb.append(dp[N][1] + " " + dp[N][0] + "\n");
        }
        System.out.print(sb);
    }
}
// https://www.acmicpc.net/problem/15993
/*
 * 
 * dp[0] = 1, dp[1] = dp[0] 1, dp[2] = dp[1] + dp[0] 2, dp[3] = dp[1] + dp[2] + dp[0] 4;
 * 0 = 홀수, 1 = 홀수 2 = 
 * dp[5] = dp[4] + dp[3] + dp[2] = 7 + 4 + 2 = 13 6 7
 * 
 * 1
 * 1
 * 2
 * 4
 * 7
 * 13
 * 1 1 1 1 1
 * 1 1 1 2
 * 1 1 2 1 
 * 1 2 1 1
 * 1 2 2 
 * 1 1 3
 * 1 3 1
 * 2 1 1 1
 * 2 2 1
 * 2 1 2
 * 2 3
 * 3 1 1
 * 3 2
 */