package BaekJoon;
import java.io.*;
class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		char[] arr = new char[N];
		for(int i = 0; i < N; i++) arr[i] = br.readLine().charAt(0);
		for (int i = 1, start = 0, end = N - 1; start <= end; i++){
			if (arr[start] != arr[end]) {
				if (arr[start] < arr[end]) sb.append(arr[start++]);
				else sb.append(arr[end--]);
			} else {
				int s = start, e = end;
				while (s <= e && arr[s] == arr[e]) {
					s++;
					e--;
				}
				if (s > e) sb.append(arr[start++]);
				else {
					if (arr[s] < arr[e]) sb.append(arr[start++]);
					else sb.append(arr[end--]);
				}
			}
			if (i % 80 == 0) sb.append("\n");
		}
		System.out.println(sb);
	}
}