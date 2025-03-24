import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        int[][] dp = new int[N][2];
        for(int i = 1; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < N; i++) {
            if (arr[i] <= K) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
            } else {
                dp[i][0] = 1;
                dp[i][1] = dp[i - 1][0] + 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            ans = Math.max(ans, dp[i][0]);
            ans = Math.max(ans, dp[i][1]);
        }
        System.out.println(ans);
    }
}

/*
 * 
 * 7 3
    2 3 1 5 3 5
1 2 3 4

3보다 커도 밟을 수 있는 경우가 최대 한번 

 */