import java.io.*;
import java.util.*;

class main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		Stack<Character> stk = new Stack<>();
		for(int i = 0; i < s.length(); i++){
			char c = s.charAt(i);
			stk.push(c);
			if (stk.size() < 4) continue;
			while (stk.size() > 3){
				String tmp = "";
				for(int j = 0; j < 4; j++) tmp += stk.pop();
				if (tmp.equals("PAPP")) stk.push('P');
				else {
					for(int j = tmp.length() - 1; j >= 0; j--) stk.push(tmp.charAt(j));
					break;
				}
			}
		}
		System.out.println((stk.size() == 1 && stk.peek() == 'P' ? "PPAP" : "NP"));
	}
}