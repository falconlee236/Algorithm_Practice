import java.io.*;
import java.util.*;
class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		long[] a = new long[N + 1], b = new long[N + 1], dp = new long[N + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= N; i++) a[i] = Long.parseLong(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= N; i++) b[i] = Long.parseLong(st.nextToken());
		for(int i = 1; i <= N; i++){
			dp[i] = Long.MAX_VALUE;
			long mx_a = 0, mx_b = 0;
			for(int j = i; j >= 1; j--){ // dp(n) = n개까지 봤을때 최소 비용 -> dp(3) -> (1, 2) (3) / (1) (2, 3) / () (1, 2, 3)
				mx_a = Math.max(mx_a, a[j]);
				mx_b = Math.max(mx_b, b[j]);
				dp[i] = Math.min(dp[j - 1] + mx_a * mx_b, dp[i]);
			}
		}
		System.out.println(dp[N]);
	}
}

/*
 * 
 * 새로 사기 vs 기존것 이어서 사기 -> 기존것을 어떻게 판단할것인가?
 * dp[1] = a * b;
 * dp[2] = min(max(a) * max(b) vs a * b)
5
0 10 9 1 7 6
0 4 2 99 4 3
dp(1) = min(10 * 4, 10 * 4 + dp(0)) = 40 l
dp(2) = min(10 * 4, 9 * 2 + dp(1)) = 40 l
dp(3) = min(99 * 10, 99 * 1 + dp(2)) = 139 r max 초기화 값 = 40
dp(4) = min(99 * 7, 7 * 4 + dp(0)) = 28 r max 초기화 값 = 40 + 99
dp(5) = min(7 * 4, 6 * 3 + dp(4)) = 28

5
1 2 3 4 5
3 2 8 9 4
dp(1) = min(1 * 3, 1 * 3 + dp(0)) = 3 같으면 l
dp(2) = min(3 * 2, 2 * 2 + dp(1)) = 6 l
dp(3) = min(8 * 3, 3 * 8 + dp(2)) = 24 l
dp(4) = min(9 * 4, 9 * 4 + dp(3)) = 36 l
dp(5) = min(9 * 5, 5 * 4 + dp(4)) = 45 l

 */