package BaekJoon;
import java.io.*;
import java.util.*;

class main {
	private void solution() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(st.nextToken());
		PriorityQueue<int[]> pq = new PriorityQueue<>((int[] o1, int[] o2) -> {
			if ((o1[0] - o1[1]) == (o2[0] - o2[1]))
				return Math.max(o2[0], o2[1]) - Math.max(o1[0], o1[1]);
			return (o2[0] - o2[1]) - (o1[0] - o1[1]);
		});
		while(T-- > 0){
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			int[] ats = new int[N];
			int[] dfs = new int[N];
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N; i++) ats[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N; i++) dfs[i] = Integer.parseInt(st.nextToken());
			for(int i = 0; i < N; i++) pq.offer(new int[]{ats[i], dfs[i]});
			long ans = 0;
			int a_cnt = 0, b_cnt = 0, cnt = 0;
			for(int i = 1; i <= N / 2; i++){
				if (N - (2 * i) <= K) {
					cnt = N - i;
					break;
				}
			}
			while (!pq.isEmpty()){
				int[] arr = pq.poll();
				if ((arr[0] >= arr[1] && a_cnt < cnt) || b_cnt == cnt){
					ans += arr[0];
					a_cnt++;
				} else if (b_cnt < cnt || a_cnt == cnt) {
					ans += arr[1];
					b_cnt++;
				}
			}
			sb.append(ans + "\n");
		}
		System.out.println(sb);
	}

	public static void main(String[] args) throws Exception{
		new main().solution();
	}	
}