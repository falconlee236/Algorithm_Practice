import java.io.*;
import java.util.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] arr = new int[M][2];
		int[] x = new int[M];
		int[] y = new int[M];
		for(int i = 0; i < M; i++){
			st = new StringTokenizer(br.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			y[i] = Integer.parseInt(st.nextToken());
			arr[i][0] = x[i];
			arr[i][1] = y[i];
		}
		Arrays.sort(x);
		Arrays.sort(y);
		int ans = Integer.MAX_VALUE;
		for(int i = x[(M - 1) / 2]; i <= x[M / 2]; i++){
			for(int j = y[(M - 1) / 2]; j <= y[M / 2]; j++) {
				int tmp = 0;
				for(int[] point : arr) tmp += Math.abs(point[0] - i) + Math.abs(point[1] - j);
				ans = Math.min(ans, tmp);
			}
		}
		System.out.println(ans);
	}	
}