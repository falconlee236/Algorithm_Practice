package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            if (N == 0 && K == 0) break;
            int[] arr = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
            long[][] dp = new long[N][K + 1];
            for(int i = 0; i < N; i++) dp[i][1] = 1;
            for(int i = 1; i < N; i++){
                for(int j = i - 1; j >= 0; j--){
                    if (arr[i] <= arr[j]) continue;
                    for(int k = 2; k <= K; k++) dp[i][k] += dp[j][k - 1];
                }
            }
            long ans = 0;
            for(int i = 0; i < N; i++) ans += dp[i][K];
            sb.append(ans + "\n");
        }
        System.out.println(sb);
    }
}