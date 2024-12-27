package BaekJoon;
import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] arr = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        long[] dp = new long[N];
        dp[0] = 0;
        for(int i = 1; i < N; i++){
            dp[i] = Long.MAX_VALUE;
            for(int j = 0; j < i; j++) dp[i] = Math.min(dp[i], Math.max(dp[j], (i - j) * (1 + Math.abs(arr[i] - arr[j]))));
        }
        System.out.println(dp[N - 1]);
    }
}