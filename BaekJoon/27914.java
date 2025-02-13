import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        long[] dp = new long[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        int sum = 0;
        if (arr[0] != K){
            sum = 1;
            dp[0] = 1;
        }
        for(int i = 1; i < N; i++){
            if (arr[i] == K) {
                dp[i] = dp[i - 1];
                sum = 0;
            }
            else {
                sum++;
                dp[i] = dp[i - 1] + sum;
            }
        }
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (Q-->0) sb.append(dp[Integer.parseInt(st.nextToken()) - 1] + "\n");
        System.out.println(sb);
    }    
}
