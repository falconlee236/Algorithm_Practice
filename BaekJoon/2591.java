package BaekJoon;
import java.io.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int N = str.length();
		int[] dp = new int[N];
		dp[0] = 1;
		for(int i = 1; i < N; i++){
			if ((str.charAt(i - 1) - '0') * 10 + (str.charAt(i) - '0') <= 34 && str.charAt(i - 1) != '0') dp[i] = (i == 1 ? 1 : dp[i - 2]);
			if (str.charAt(i) != '0') dp[i] += dp[i - 1];
		}
		System.out.println(dp[N - 1]);
	}
}