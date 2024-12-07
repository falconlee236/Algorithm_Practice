import java.io.*;
import java.util.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(st.nextToken());
		for(int i = 0; i < T; i++){
			st = new StringTokenizer(br.readLine());
			int ans = 0, mn = Integer.MAX_VALUE;
			for(int j = 0; j < 7; j++){
				int num = Integer.parseInt(st.nextToken());
				if (num % 2 == 0) {
					ans += num;
					mn = Math.min(mn, num);
				}
			}
			sb.append(ans).append(" ").append(mn).append("\n");
		}
		System.out.println(sb);
	}	
}