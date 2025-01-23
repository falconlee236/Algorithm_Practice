package BaekJoon;
import java.io.*;
import java.util.*;
class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		char[] arr = new char[N];
		for(int i = 0; i < N; i++) arr[i] = st.nextToken().charAt(0);
		boolean flag = (arr[0] == 'F' ? false : true);
		char op = 'a';
		for(int i = 1; i < N - 1; i++){
			if (i % 2 != 0){
				op = arr[i];
				continue;
			}
			boolean tmp = (arr[i] == 'F' ? false : true);
			flag = (op == '&' ? flag && tmp : flag || tmp);
		}
		boolean base = (br.readLine().charAt(0) == 'F' ? false : true);
		if (N == 1){
			System.out.println((base == flag ? 0 : 1));
			return;
		}
		int ans = 0;
		if (flag) {
			if (op == '&'){
				if (base) ans = (arr[N - 1] == 'F' ? 1 : 0); // T & ? = T
				else ans = (arr[N - 1] == 'F' ? 0 : 1); // T & ? = F
			} else {
				if (base) ans = 0; // T | ? = T
				else ans = (arr[N - 1] == 'F' ? 1 : 2); // T | ? = F
			}
		} else {
			if (op == '&'){
				if (base) ans = (arr[N - 1] == 'F' ? 2 : 1); // F & ? = T
				else ans = 0; // F & ? = F
			} else {
				if (base) ans = (arr[N - 1] == 'F' ? 1 : 0); // F | ? = T
				else ans = (arr[N - 1] == 'F' ? 0 : 1); // F | ? = F
			}
		}
		System.out.println(ans);
	}
}