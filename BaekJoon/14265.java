package BaekJoon;
import java.util.*;
import java.io.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long K = Long.parseLong(st.nextToken());
		long A = Long.parseLong(st.nextToken());
		long B = Long.parseLong(st.nextToken()) + 1;
		long KK = K + 1, tmp = K, ans = 0;
		if (K == 0){
			System.out.println(B - A);
			return;
		}
		while (K < B){
			if (A < KK) ans += Math.min(B, KK) - Math.max(A, K);
			K <<= 1;
			KK <<= 1;
		}
		if (tmp % 2 == 0){
			K = tmp + 1;
			KK = tmp + 2;
			while (K < B){
				if (A < KK) ans += Math.min(B, KK) - Math.max(A, K);
				K <<= 1;
				KK <<= 1;
			}	
		}
		System.out.println(ans);
	}	
}
/*
 * 이진수 관점으로 생각하면 X에서 Y에 도달하기 위해서 Y의 자릿수가 X로 시작하거나 짝수인 경우 X+1로 시작해야함
 * 
 * K = 3
 * 
 * 5 <= x <= 12
 * 3 -> 11
 * 4 -> 100
 * 5 -> 101
 * 6 -> 110
 * 7 -> 111
 * 8 -> 1000
 * 9 -> 1001
 * 10 -> 1010
 * 11 -> 1011
 * 12 -> 1100
 * 
 * 0
 * 1 0
 * 2 1 0
 * 3 2 1 0
 * 4 2 1 0
 * 5 4 2 1 0
 * 6 3 2 1 0
 * 7 6 3 2 1 0
 * 8 4 2 1 0
 * 9 8 4 2 1 0
 * 10 5 4 2 1 0
 * 11 10 5 4 2 1 0
 * 12 6 3 2 1 0
 * 최악의 경우는 0 ~ 10^18
 * 3 <- 6 에서만 올 수 있음 = 홀수는 홀수 * 2 에서만 올 수 있음
 * 4 <- 8 or 5 에서 올 수 있음 = 짝수는 짝수 * 2 or 짝수 + 1 에서 올 수 있음
 * K > B인 경우는? ex) K = 9 답이 없음.
 * 이거 수식 한줄로 가능할거 같은데 왜냐하면 반복문 해도 터짐
 */