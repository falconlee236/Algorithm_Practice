package BaekJoon;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), mod = 1_000_000_007;
        if (N == 1) {
            System.out.println(0);
            return;
        }
        int[][] dp = new int[N + 1][3];
        dp[2][0] = 1;
        dp[2][1] = 1;
        for(int i = 3; i <= N; i++){
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod; // (1 + 5) % 3 = 0, (2 + 1) % 3 = 0
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % mod; // (2 + 5) % 3 = 1, (0 + 1) % 3 = 1
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod; // (0 + 5) % 3 = 2, (1 + 1) % 3 = 2;
        }
        System.out.println(dp[N][0]);
    }    
}

// dp (n) -> 1과 5로만 이루어진 n자리 양의 정수 중에서 15의 배수
// dp (1) = 0
// dp(2) = 11 15 51 55 -> 15
/*
 * dp(N, 0) -> 자릿수가 N이고 3으로 나눈 나머지가 0
 * dp(N, 1) -> 자릿수가 N이고, 3으로 나눈 나머지가 1
 * dp(N, 2) -> 자릿수가 N이고, 3으로 나눈 나머지가 2
 * 단 1, 5로만 이루어진 수에서, 맨 뒤 고정
 * dp(2, 0) = 15 = 1
 * dp(2, 1) = 55 = 1
 * dp(2, 2) = 0 
 */