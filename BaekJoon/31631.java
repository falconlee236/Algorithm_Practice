import java.io.*;
import java.util.*;

class main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		ArrayList<Integer> list = new ArrayList<>(N);
		list.add(1);
		list.add(2);
		for(int i = 2; i < N; i++){
			for(int j = 0; j < i; j++) list.set(j, list.get(j) + 1);
			int idx = i % 4;
			if (idx % 2 == 0) idx = (i >> 1);
			else if (idx == 1) idx = (i - 1) >> 1;
			else idx = ((i - 1) >> 1) + 1;
			list.add(idx, 1);
		}
		for(int x : list) sb.append(x).append(' ');
		System.out.println(sb);
	}	
}