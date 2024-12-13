package BaekJoon;
import java.util.*;
import java.io.*;

class main {
	private int N, M, mn, ans;
	private int[] bitset;
	private void solve(int idx, int cnt, int sum, int use){
		if (cnt >= mn) return;
		if (idx == N){
			if (sum == (1 << M) - 1){
				mn = cnt;
				ans = use;
			}
			return;
		}
		solve(idx + 1, cnt + 1, sum | bitset[idx], use | (1 << idx));
		solve(idx + 1, cnt, sum, use);
	}

	private void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(st.nextToken());
		for (int t = 1; t <= T; t++){
			st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			bitset = new int[N];
			mn = 21;
			ans = 0;
			for(int i = 0; i < N; i++){
				st = new StringTokenizer(br.readLine());
				while (st.hasMoreTokens()) bitset[i] |= (1 << (Integer.parseInt(st.nextToken()) - 1));
			}
			solve(0, 0, 0, 0);	
			sb.append("Data Set " + t + ": ");
			for(int i = 0; i < N; i++) {
				if ((ans & (1 << i)) != 0) sb.append((char)('A' + i) + " ");
			}
			sb.append("\n\n");
		}
		System.out.println(sb);
	}
	public static void main(String[] args) throws Exception{
		new main().solution();
	}
}