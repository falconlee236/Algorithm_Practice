import java.io.*;
import java.util.*;
class Main {
    long[][] dp = new long[1000][1000];
    private long solve(int k, int n){
        if (dp[k][n] != -1) return dp[k][n];
        if (k == 0) return 0;
        if (n == 0) return 1;
        dp[k][n] = solve(k + 1, n - 1) + solve(k - 1, n - 1);
        return dp[k][n];
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken());
        for(int i = 0; i < 1000; i++) Arrays.fill(dp[i], -1);
        System.out.println(solve(K, N));
    }
    public static void main(String args[]) throws Exception{
        new Main().solution();
    }
}