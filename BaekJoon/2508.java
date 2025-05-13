import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            br.readLine();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), ans = 0;
            char[][] arr = new char[N][M];
            for(int i = 0; i < N; i++){
                String line = br.readLine();
                for(int j = 0; j < M; j++) arr[i][j] = line.charAt(j);
            }
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M - 2; j++){
                    if(arr[i][j] == '>' && arr[i][j + 1] == 'o' && arr[i][j + 2] == '<') ans++;
                }
            }
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N - 2; j++) {
                    if (arr[j][i] == 'v' && arr[j + 1][i] == 'o' && arr[j + 2][i] == '^') ans++;
                }
            }
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }    
}
