package BaekJoon;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] dp = new int[191230];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i < 191230; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            int N = Integer.parseInt(br.readLine());
            sb.append(dp[N] + "\n");
        }
        System.out.print(sb);
    }
}