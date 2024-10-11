import java.io.*;
class main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		for(int t = 0; t < T; t++){
			String[] input = br.readLine().split(" ");
			int W = Integer.parseInt(input[0]), N = Integer.parseInt(input[1]), ans = 0, cur = 0, a = 0, b;
			for(int i = 0; i < N; i++){
				input = br.readLine().split(" ");
				a = Integer.parseInt(input[0]);
				b = Integer.parseInt(input[1]);
				cur += b;
				if (cur > W) {
					ans += a;
					cur = b;
				}
				if (cur == W) {
					ans += a;
					cur = 0;
				}
			}
			if (cur > 0) ans += a;
			bw.write(String.valueOf(ans * 2) + "\n");
			bw.flush();
		}
	}
}