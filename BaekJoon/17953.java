package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int[][] arr = new int[M][N], dp = new int[M][N];
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if (i == 0) dp[j][i] = arr[j][i];
                else {
                    for(int k = 0; k < M; k++) dp[j][i] = Math.max(dp[j][i], dp[k][i - 1] + (k == j ? arr[j][i] / 2 : arr[j][i]));
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < M; i++) ans = Math.max(ans, dp[i][N - 1]);
        System.out.println(ans);
    }
}

/*
 * 
 * dp[i][j] = i번째 날에 j번째 디저트를 먹었을 때 최대 만족도
 * dp[0][j] = arr[0][j] 초기값
 * dp[1][j] = dp[0][k] + arr[1][j]인데 k == j이면 arr[1][j] / 2
 */