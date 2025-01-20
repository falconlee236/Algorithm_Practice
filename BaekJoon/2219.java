package BaekJoon;
import java.io.*;
import java.util.*;
class main {
	public static void main(String[] args) throws Exception{
		final int MAX = 100000000;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] cost = new int[N + 1][N + 1];
		for(int i = 0; i <= N; i++) Arrays.fill(cost[i], MAX);
		for(int i = 0; i < M; i++){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			cost[a][b] = c;
			cost[b][a] = c;
		}
		for(int k = 1; k <= N; k++){
			for(int i = 1; i <= N; i++){
				for(int j = 1; j <= N; j++) cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
		int mn = MAX, ans = N;
		for(int i = 1; i <= N; i++){
			int tmp = 0;
			for(int j = 1; j <= N; j++) tmp += cost[i][j];
			if (mn > tmp){
				ans = i;
				mn = Math.min(mn, tmp);
			}
		}
		System.out.println(ans);
	}
}