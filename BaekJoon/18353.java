import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] dp = new int[N], arr = new int[N];
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
            dp[i] = 1;
            for(int j = i - 1; j >= 0; j--){
                if (arr[i] < arr[j]) dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++) ans = Math.max(dp[i], ans);
        System.out.println(N - ans);
    }    
}