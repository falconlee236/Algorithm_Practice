import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), ans = 0;
        int[][] arr = new int[N][M], dp = new int[N + 1][M + 1];
        for(int i = 0; i < N; i++) arr[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++) {
                dp[i][j] = Math.max(dp[i - 1][j],  dp[i][j - 1]) + arr[i - 1][j - 1];
                ans = Math.max(ans, dp[i][j]);
            }
        }
        System.out.println(ans);
    }
}
