package BaekJoon;
import java.io.*;
import java.util.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(st.nextToken());
		while (T-->0){
			int N = Integer.parseInt(br.readLine());
			int[][] node = new int[N + 2][2];
			for(int i = 0; i < N + 2; i++){
				st = new StringTokenizer(br.readLine());
				node[i][0] = Integer.parseInt(st.nextToken());
				node[i][1] = Integer.parseInt(st.nextToken());
			}
			boolean[] v = new boolean[N + 2];
			boolean flag = false;
			Queue<Integer> q = new LinkedList<>();
			q.offer(0);
			v[0] = true;
			while(!q.isEmpty()){
				int cur = q.poll();
				if (Math.abs(node[cur][0] - node[N + 1][0]) + Math.abs(node[cur][1] - node[N + 1][1]) <= 1000){
					flag = true;
					break;
				}
				for(int i = 1; i < N + 2; i++){
					if (Math.abs(node[cur][0] - node[i][0]) + Math.abs(node[cur][1] - node[i][1]) > 1000 || v[i]) continue;
					q.offer(i);
					v[i] = true;
				}
			}
			sb.append((flag ? "happy\n" : "sad\n"));
		}
		System.out.println(sb);
	}	
}