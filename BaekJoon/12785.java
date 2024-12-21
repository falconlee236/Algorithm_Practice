package BaekJoon;
import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        long[][] dp = new long[w + 1][h + 1];
        for(int i = 0; i <= w; i++) dp[i][1] = 1;
        for(int i = 0; i <= h; i++) dp[1][i] = 1;
        long DIV = 1_000_007;
        for(int i = 2; i <= w; i++){
            for(int j = 2; j <= h; j++) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % DIV;
        }
        System.out.println((dp[x][y] * dp[w - x + 1][h - y + 1]) % DIV);
    }
}