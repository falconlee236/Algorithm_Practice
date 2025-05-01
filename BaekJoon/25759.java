package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()), ans = 0;
        int[] dp = new int[101];
        Arrays.fill(dp, -1);
        dp[start] = 0;
        for(int i = 1; i < N; i++){
            int num = Integer.parseInt(st.nextToken());
            for(int j = 1; j <= 100; j++) {
                int dist = Math.abs(num - j);
                if (dp[j] > -1) dp[num] = Math.max(dp[num], dp[j] + dist * dist);
            }
        }
        for(int x : dp) ans = Math.max(ans, x);
        System.out.println(ans);
    }
}