package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][N], dp = new int[N][N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if (dp[i][j] == Integer.MAX_VALUE) continue;
                if (i + arr[i][j] < N) dp[i + arr[i][j]][j] = Math.min(dp[i + arr[i][j]][j], dp[i][j] + 1);
                if (j + arr[i][j] < N) dp[i][j + arr[i][j]] = Math.min(dp[i][j + arr[i][j]], dp[i][j] + 1);
            }
        }
        System.out.println((dp[N - 1][N - 1] == Integer.MAX_VALUE ? "Hing" : "HaruHaru"));
    }
}