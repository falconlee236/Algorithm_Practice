import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (T-->0){
            String str = br.readLine();
            int N = (int)Math.sqrt(str.length());
            char[][] arr = new char[N][N], tmp = new char[N][N];
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) arr[i][j] = str.charAt(i * N + j);
            }
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) tmp[i][j] = arr[j][N - i - 1];
            }
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) sb.append(tmp[i][j]);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
// https://www.acmicpc.net/problem/5426