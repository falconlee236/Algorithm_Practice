import java.util.*;
import java.io.*;

class Main{
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringBuilder result = new StringBuilder();
	
	static int[] P;
	static int[] ans;
	static boolean[] visit;
	static int T;
	static int N;

	public static void main(String[] args) throws IOException{

		T = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < T; i++){
			
			N = Integer.parseInt(br.readLine());	
			P = new int[N*2];
			ans = new int[N];
			visit = new boolean[N*2];
			
			String s = br. readLine();
			String[] array = s.split(" ");
			for(int j = 0; j < N*2; j++){
				P[j] = Integer.parseInt(array[j]);
			}
			

			int count = 0;
			for(int k = 0; k < N*2; k++){
				if(count == N) break;
				if(visit[k] || P[k]%3 != 0) // 방문한 적 있거나 할인가 아닌 경우
					continue;	// 다음 배열로
					
				visit[k] = true;    // 할인가 방문 처리
				long price = (P[k] / 3) * 4;	// 원가 계산
				for(int j = k + 1; j < N*2; j++){
					if(!visit[j] && price == P[j]){	// 방문한 적 없고 P[j]가 원가랑 같으면
						ans[count] = P[k];	// ans 배열에 할인가인 P[k] 저장
						visit[j] = true;    // 원가 방문 처리
						count++;
						break;		// 탈출
					}
				}
			}

			result.append("Case #").append(i+1).append(": ");
			for(int j = 0; j < N; j++){
				result.append(ans[j]).append(' ');
			}
			result.append('\n');
		}
		
		br.close();
		
		bw.write(result.toString());
		bw.flush();
		bw.close();

	}
}