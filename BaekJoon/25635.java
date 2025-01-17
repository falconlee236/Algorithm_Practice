package BaekJoon;
import java.io.*;
import java.util.*;
class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		long sum = 0, mx = 0;
		for(int i = 0; i < N; i++) {
			long num = Long.parseLong(st.nextToken()); 
			sum += num;
			mx = Math.max(num, mx);
		}
		sum -= mx;
		System.out.println((mx > sum + 1 ? sum * 2 + 1 : sum + mx));
	}
}