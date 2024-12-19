package BaekJoon;
import java.io.*;
import java.util.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine()), sum = 0, ans = 0, mn = Integer.MAX_VALUE;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			int num = Integer.parseInt(st.nextToken());
			sum ^= num;
			ans += num;
			mn = Math.min(mn, num);
		}
		System.out.println((sum == 0 ? ans - mn : 0));
	}
}