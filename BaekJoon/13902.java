package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[M];
        int[] dp = new int[10001];
        st = new StringTokenizer(br.readLine());
        TreeSet<Integer> s = new TreeSet<>();
        for(int i = 0; i < M; i++) arr[i] = Integer.parseInt(st.nextToken());
        for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                if (i == j) s.add(arr[i]);
                else s.add(arr[i] + arr[j]);
            }
        }
        for(int i = 1; i <= N; i++){
            dp[i] = 1000000;
            for (int j : s) {
                if (i - j < 0) break;
                dp[i] = Math.min(dp[i], dp[i - j] + 1);
            }
        }
        System.out.println((dp[N] == 1000000 ? -1 : dp[N]));
    } 
}