package BaekJoon;
import java.io.*;
import java.util.*;
class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int[] rock = new int[K], dp = new int[N + 1], ans = new int[M];
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= N; i++) dp[i] = dp[i - 1] + Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < K; i++) rock[i] = Integer.parseInt(st.nextToken());
		int[][] tmp = new int[K][2];
		for(int i = 0; i < K - 1; i++) tmp[i] = new int[]{rock[i], dp[rock[i + 1] - 1] - dp[rock[i] - 1]};
		tmp[K - 1] = new int[]{rock[K - 1], dp[N] - dp[rock[K - 1] - 1]};
		Arrays.sort(tmp, (o1, o2) -> o2[1] - o1[1]);
		for(int i = 0; i < M; i++) ans[i] = tmp[i][0];
		Arrays.sort(ans);
		for (int x : ans) sb.append(x + "\n");
		System.out.print(sb);
	}
}

/*
 * 
 * 
 * M == K 이면 항상 M이 있는 위치에 벽을 세우면 되기 때문에 0개가 부서짐
 * M < K 이면 문제
 * K개 돌 중에서 큰 순서대로 벽을 놓으면? 나머지 돌이 <오른쪽으로> 굴러감
 * 돌과 돌 사이 모래성의 개수가 작은 순서대로 넣어야 할듯 -> 누적합
 * 즉 돌을 안두는 위치를 정하면 된다.
 * 누적합
 * 2 7 10 17 18 24 32
 * 벽 x x 돌  벽  x x
 * 
 * 그럼 만약 벽이 1개 뿐이라면?
 * 2 7 10 17 18 24 32
 * 돌 x x  돌 벽  x  x
 * 1 2  3  4  5  6  7
 * dp(돌 - 1) - dp(돌 - 1) = dp(4 - 1) - dp(1 - 1) = 10
 * dp(5 - 1) - dp (4 - 1) = 7
 * dp(8 - 1) - dp(5 - 1) = 15
 * 
 * 
 * 2 5 3 7 1 1 1
 * 돌    돌 돌
 * 2 7 10 17 18 19 20
 * 10, 7, 3
 * 
 * 벽        
 * 
 */