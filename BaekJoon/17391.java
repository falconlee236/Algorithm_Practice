package BaekJoon;
import java.io.*;
import java.util.*;
//https://www.acmicpc.net/problem/17391
public class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), MAX = 0xFFFFF;
        int arr[][] = new int[N][M], dp[][] = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = MAX;
            }
        }
        dp[0][0] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                for(int ii = i + 1; ii < Math.min(N, i + 1 + arr[i][j]); ii++) dp[ii][j] = Math.min(dp[ii][j], dp[i][j] + 1);
                for(int jj = j + 1; jj < Math.min(M, j + 1 + arr[i][j]); jj++) dp[i][jj] = Math.min(dp[i][jj], dp[i][j] + 1);
            }
        }
        System.out.println(dp[N - 1][M - 1]);
    }
}
