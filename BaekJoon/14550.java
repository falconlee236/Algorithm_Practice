import java.util.*;
import java.io.*;
class main {
    int N, S, T, MIN = -0xFFFFF;
    int[] arr;
    int[][] dp; // dp[t][n] = t라운드에서 n번째 칸에 도착할때 최대 값
    private int solve(int t, int n){
        if (t == 0 || n == 0 || dp[t][n] != MIN) return dp[t][n];
        int tmp = MIN;
        for(int i = 1; i <= S && n >= i; i++) tmp = Math.max(tmp, solve(t - 1, n - i));
        return (dp[t][n] = tmp + arr[n]);
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            if (N == 0) break;
            S = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());
            arr = new int[N + 2];
            dp = new int[T + 1][N + 2]; //0 -> 시작, N + 1 -> 도착
            for(int i = 0; i <= T; i++){
                for(int j = 0; j <= N + 1; j++) dp[i][j] = MIN;
            }
            int idx = 1;
            while (idx <= N) {
                st = new StringTokenizer(br.readLine());
                while (st.hasMoreTokens()) arr[idx++] = Integer.parseInt(st.nextToken());
            }
            dp[0][0] = 0;
            sb.append(solve(T, N + 1) + "\n");
        }
        System.out.print(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}
