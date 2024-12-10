import java.io.*;
import java.util.*;
class main {
	String str;
	int ans;
	HashSet<String> s;
	private void solve(String res, String path){
		if (s.contains(path)) return;
		s.add(path);
		if (str.equals(res)){
			ans++;
			return;
		}
		for(int i = 0; i < str.length(); i++){
			if (str.contains(res + str.charAt(i))) solve(res + str.charAt(i), path + " " + res + str.charAt(i));
			if (str.contains(str.charAt(i) + res)) solve(str.charAt(i) + res, path + " " + str.charAt(i) + res);
		}
	}
	private void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();
		s = new HashSet<>();
		solve("", "");
		System.out.println(ans);
	}
	public static void main(String[] args) throws Exception{
		new main().solution();
	}	
}