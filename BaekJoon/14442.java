import java.io.*;
import java.util.*;
class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		char[][] arr = new char[N][M];
		boolean[][][] v = new boolean[N][M][K + 1];
		for(int i = 0; i < N; i++){
			String line = br.readLine();
			for(int j = 0; j < M; j++){
				arr[i][j] = line.charAt(j);
			}
		}
		int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[]{0, 0, 0, 1});
		v[0][0][0] = true;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			if (cur[0] == N - 1 && cur[1] == M - 1) {
				System.out.println(cur[3]);
				return;
			}
			for(int i = 0; i < 4; i++){
				int nx = dx[i] + cur[0], ny = dy[i] + cur[1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (arr[nx][ny] == '0' && !v[nx][ny][cur[2]]) {
					v[nx][ny][cur[2]] = true;
					q.offer(new int[]{nx, ny, cur[2], cur[3] + 1});
				}
				if (arr[nx][ny] == '1' && cur[2] < K && !v[nx][ny][cur[2] + 1]) {
					v[nx][ny][cur[2] + 1] = true;
					q.offer(new int[]{nx, ny, cur[2] + 1, cur[3] + 1});
				}
			}
		}
		System.out.println(-1);
	}	
}