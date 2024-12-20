package BaekJoon;
import java.util.*;
import java.io.*;

class main {
	private static int gcd(int a, int b){
		if (a % b == 0) return b;
		return gcd(b, a % b);
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine()), ans = 1;
		int[] arr = new int[N + 1];
		boolean[] v = new boolean[N + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= N; i++) arr[i] = Integer.parseInt(st.nextToken());
		for(int i = 1; i <= N; i++){
			int cnt = 0;
			if (v[i]) continue;
			for(int j = i; !v[j]; j = arr[j]){
				v[j] = true;
				cnt++;
			}
			ans = (int) (((long) ans * (long) cnt) / gcd(ans, cnt));
		}
		System.out.println(ans);
	}
}

/*
 * 3 2 5 6 1 4
 * 
 * 1 2 3 4 5 6
 * 3 2 5 6 1 4
 * 5 2 1 4 3 6
 * 1 2 3 6 5 4
 * 3 2 5 4 1 6
 * 5 2 1 6 3 4
 * 1 2 3 4 5 6
 * 
 * 1. 배열 저장 
 * 2. N번 반복
 * 3. 각 자리수에 대해서 이동 거리를 구함
 * 4. 최소 공배수가 답.
 */


