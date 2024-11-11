import java.io.*;
import java.util.*;;

class main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] dp = new int[n][m];
		int[][] arr = new int[n][m];
		int ans = 0;
		for(int i = 0; i < n; i++){
			String s = br.readLine();
			for(int j = 0; j < m; j++){
				arr[i][j] = s.charAt(j) - '0';
				if (j == 0) dp[i][j] = arr[i][j];
			}
		}
		for(int i = 1; i < m; i++){
			for(int j = 0; j < n; j++){
				if (j > 0) dp[j][i] = Math.max(dp[j - 1][i - 1], dp[j][i]);
				if (j < n - 1) dp[j][i] = Math.max(dp[j + 1][i - 1], dp[j][i]);
				dp[j][i] = Math.max(dp[j][i - 1], dp[j][i]);
				ans = Math.max(ans, dp[j][i]);
				dp[j][i] += arr[j][i];
			}
		}
		System.out.println(ans);
	}
}