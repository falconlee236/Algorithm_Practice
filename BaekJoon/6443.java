import java.io.*;
class main {
	BufferedWriter bw;
	String s;
	int[] arr;
	boolean[] v;
	char[] res;
	private void dfs(int cnt) throws Exception {
		if (cnt == s.length()){
			bw.write(String.valueOf(res) + "\n");
			return;
		}
		for(int i = 0; i < arr.length; i++){
			if (arr[i] == 0) continue;
			arr[i]--;
			res[cnt] = (char) (i + 'a');
			dfs(cnt + 1);
			arr[i]++;
		}
	}
	private void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		while (T-->0){
			s = br.readLine();
			arr = new int[26];
			res = new char[s.length()];
			for(int i = 0; i < s.length(); i++) arr[s.charAt(i) - 'a']++;
			dfs(0);
		}
		bw.close();
	}
	public static void main(String[] args) throws Exception{
		new main().solution();
	}	
}