package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        int[] dp = new int[N + 1];
        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());
            int cost = Integer.parseInt(st.nextToken()), value = Integer.parseInt(st.nextToken());
            for(int j = N; j >= cost; j--) dp[j] = Math.max(dp[j - cost] + value, dp[j]);
        }
        System.out.println(dp[N]);
    }
}
