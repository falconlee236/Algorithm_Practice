import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        char[][] arr = new char[N + 2][N + 2];
        for(int i = 0; i <= N + 1; i++) Arrays.fill(arr[i], '@');
        for(int i = 1; i < N + 1; i++){
            for(int j = 1; j < N + 1; j++) arr[i][j] = ' ';
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i <= N + 1; i++){
            for(int j = 0; j <= N + 1; j++) sb.append(arr[i][j]);
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
