import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine()), INF = 0xFFFFFF;
        int[][] arr = new int[N][N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 0) arr[i][j] = INF;
            }
        }
        for(int k = 0; k < N; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) sb.append((arr[i][j] != INF ? 1 : 0)).append(" ");
            sb.append("\n");
        }
        System.out.print(sb);
    }
}