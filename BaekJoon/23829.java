import java.io.*;
import java.util.*;

class main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		long[] arr = new long[N];
		long[] dp = new long[N + 1];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) arr[i] = Long.parseLong(st.nextToken());
		Arrays.sort(arr);
		for(int i = 0; i < N; i++) dp[i + 1] = dp[i] + arr[i];
		for(int i = 0; i < Q; i++){
			long target = Long.parseLong(br.readLine());
			int start = 0, end = N;
			while (start < end){
				int mid = (start + end) / 2;
				if (target > arr[mid]) start = mid + 1;
				else end = mid;
			}
			sb.append(Long.toString(dp[N] - dp[start] - (target * Long.valueOf(N - start)) + target * Long.valueOf(start) - dp[start])).append('\n');
		}
		System.out.println(sb);
	}
}