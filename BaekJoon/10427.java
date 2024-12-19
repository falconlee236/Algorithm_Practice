package BaekJoon;
import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[] arr = new int[N + 1];
            for(int i = 1; i <= N; i++) arr[i] = Integer.parseInt(st.nextToken());
            Arrays.sort(arr);
            long[] dp = new long[N + 1];
            for(int i = 1; i <= N; i++) dp[i] = dp[i - 1] + (long)arr[i];
            long res = 0;
            for(int i = 2; i <= N; i++){
                long tmp = Long.MAX_VALUE;
                for(int j = i; j <= N; j++) tmp = Math.min(tmp, (arr[j] * i) - (dp[j] - dp[j - i]));
                res += tmp;
            }
            sb.append(res + "\n");
        }
        System.out.print(sb);
    }
}