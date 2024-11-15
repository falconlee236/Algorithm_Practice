import java.io.*;
import java.util.*;

public class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n + 1][n + 1];
		int[][] dp = new int[n + 1][n + 1];
		for(int i = 1; i <= n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= n; j++){
				arr[i][j] = Integer.parseInt(st.nextToken());
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
			}
		}
		int ans = Integer.MIN_VALUE;
		for(int k = 0; k < n; k++){
			for(int i = 1; i <= n - k; i++){
				for(int j  = 1; j <= n - k; j++) ans = Math.max(ans, dp[i + k][j + k] - dp[i - 1][j + k] - dp[i + k][j - 1] + dp[i - 1][j - 1]);
			}
		}
		System.out.println(ans);
	}
}