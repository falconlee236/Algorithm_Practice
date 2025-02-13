package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int[][] sum = new int[N][M], dp = new int[N][M];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                sum[i][j] = Integer.parseInt(st.nextToken()) + (i != 0 ? sum[i - 1][j] : 0);
                dp[i][j] = sum[i][j] + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
            }
        }
        while (Q-->0){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            sb.append(dp[a][b] + "\n");
        }
        System.out.print(sb);
    }
}