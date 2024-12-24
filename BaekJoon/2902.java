package BaekJoon;
import java.io.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String[] lst = br.readLine().split("-");
		for (String s : lst) sb.append(s.charAt(0));
		System.out.println(sb);
	}
}