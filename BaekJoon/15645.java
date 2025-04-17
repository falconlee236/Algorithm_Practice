import java.io.*;
import java.util.*;
class main {
  public static void main(String args[]) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int N = Integer.parseInt(br.readLine());
      int[][] arr = new int[N + 1][3], mn = new int[N + 1][3], mx = new int[N + 1][3];
      for(int i = 1; i <= N; i++){
          StringTokenizer st = new StringTokenizer(br.readLine());
          for(int j = 0; j < 3; j++) arr[i][j] = Integer.parseInt(st.nextToken());
      }
      for(int i = 1; i <= N; i++){
          mx[i][0] = Math.max(mx[i - 1][0], mx[i - 1][1]) + arr[i][0];
          mx[i][1] = Math.max(mx[i - 1][0], Math.max(mx[i - 1][1], mx[i - 1][2])) + arr[i][1];
          mx[i][2] = Math.max(mx[i - 1][1], mx[i - 1][2]) + arr[i][2];
          mn[i][0] = Math.min(mn[i - 1][0], mn[i - 1][1]) + arr[i][0];
          mn[i][1] = Math.min(mn[i - 1][0], Math.min(mn[i - 1][1], mn[i - 1][2])) + arr[i][1];
          mn[i][2] = Math.min(mn[i - 1][1], mn[i - 1][2]) + arr[i][2];
      }
      System.out.println(Math.max(mx[N][0], Math.max(mx[N][1], mx[N][2])) + " " + Math.min(mn[N][0], Math.min(mn[N][1], mn[N][2])));
  }
}