import java.io.*;
import java.util.*;
class main {
  public static void main(String args[]) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringBuilder sb = new StringBuilder();
      int T = Integer.parseInt(br.readLine());
      while(T-->0){
          int N = Integer.parseInt(br.readLine());
          float[] w = new float[N], c = new float[N];
          int[] dp = new int[N];
          for(int i = 0; i < N; i++){
              StringTokenizer st = new StringTokenizer(br.readLine());
              w[i] = Float.parseFloat(st.nextToken());
              c[i] = Float.parseFloat(st.nextToken());
          }
          for(int i = 0; i < N; i++){
              dp[i] = 1;
              for(int j = i - 1; j >= 0; j--){
                  if (w[i] > w[j] && c[i] < c[j]) dp[i] = Math.max(dp[i], dp[j] + 1);
              }
          }
          int ans = 0;
          for(int i = 0; i < N; i++) ans = Math.max(ans, dp[i]);
          sb.append(ans + "\n");
      }
      System.out.println(sb);
  }
}