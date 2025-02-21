package BaekJoon;
import java.io.*;
/*
 * 
 * dp[i] = min(dp[i], dp[i - 1 >= 0] + (i - (i - 1)) ^ 2)
 */
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), INF = 0xFFFFFF;
        char[] arr = br.readLine().toCharArray();
        int[] dp = new int[N];
        for(int i = 1; i < N; i++) dp[i] = INF;
        for(int i = 1; i < N; i++){
            char tmp;
            if (arr[i] == 'B') tmp = 'J';
            else if (arr[i] == 'O') tmp = 'B';
            else tmp = 'O';
            for(int j = i - 1; j >= 0; j--){
                if (tmp != arr[j]) continue;
                dp[i] = Math.min(dp[i], dp[j] + (i - j) * (i - j));
            }
        }
        System.out.println((dp[N - 1] == INF ? -1 : dp[N - 1]));
    }    
}