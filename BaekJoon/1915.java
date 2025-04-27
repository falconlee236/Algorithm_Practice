package BaekJoon;
import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), mx = 0;
        int[][] arr = new int[N + 1][M + 1], dp = new int[N + 1][M + 1];
        for(int i = 1; i <= N; i++){
            String str = br.readLine();
            for(int j = 1; j <= M; j++) arr[i][j] = str.charAt(j - 1) == '1' ? 1 : 0;
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if (arr[i][j] == 0) continue;
                dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                mx = Math.max(dp[i][j] * dp[i][j], mx);
            }
        }
        System.out.println(mx);
    }
}