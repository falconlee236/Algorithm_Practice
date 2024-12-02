import java.io.*;
import java.util.*;

class main {
	int N, M, ans;
	int[][] arr;
	boolean[][] visit;
	final int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	private void dfs(int x, int y, int before, int cap, int res){
		if (cap < 0) return;
		ans = Math.max(res, ans);
		if (cap == 0) return;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			dfs(nx, ny, i, cap - (before == -1 || before == i ? 1 : 2), res + arr[nx][ny]);
			visit[nx][ny] = false;
		}
	}
	private void solution() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		visit = new boolean[N][M];
		for(int i = 0; i < N; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++){
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int cap = Integer.parseInt(st.nextToken());
		visit[x][y] = true;
		dfs(x, y, -1, cap, arr[x][y]);
		System.out.println(ans);
	}
	public static void main(String[] args) throws Exception{
		new main().solution();
	}
}