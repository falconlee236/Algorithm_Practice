import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), ans = 0;
        int[] arr = new int[N], dp = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        dp[0] = 1;
        for(int i = 1; i < N; i++){
            for(int j = i - 1; j >= 0; j--){
                if (arr[j] < arr[i]) dp[i] = Math.max(dp[i], dp[j]);
            }
            dp[i]++;
        }
        for (int i : dp) ans = Math.max(ans, i);
        System.out.println(ans);
    }
}