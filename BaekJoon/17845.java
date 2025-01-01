package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] weight = new int[K + 1];
        int[] cost = new int[K + 1];
        int[][] dp = new int[K + 1][N + 1];
        for(int i = 1; i <= K; i++){
            st = new StringTokenizer(br.readLine());
            weight[i] = Integer.parseInt(st.nextToken());
            cost[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 1; i <= K; i++){
            for(int j = 1; j <= N; j++){
                if (j - cost[i] < 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - cost[i]] + weight[i]);
            }
        }
        System.out.println(dp[K][N]);
    }
}

/*
 * dp[i][j] = i번째 상품을 선택할 때 최대 공부시간이 N 일 때 최대 가치
 * = i 번째 상품을 선택하지 않는 경우 vs i번째 상품을 선택하는 경우
 * = dp[i - 1][j] vs dp[i - 1][j - cost[i]] + weight[i]
 */
