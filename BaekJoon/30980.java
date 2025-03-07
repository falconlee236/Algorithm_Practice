import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        char[][] arr = new char[3 * N][8 * M];
        for(int i = 0; i < 3 * N; i++) arr[i] = br.readLine().toCharArray();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int x = arr[i * 3 + 1][j * 8 + 1] - '0';
                int y = arr[i * 3 + 1][j * 8 + 3] - '0';
                int z = arr[i * 3 + 1][j * 8 + 5] - '0';
                if (arr[i * 3 + 1][j * 8 + 6] != '.') z = (z * 10) + (arr[i * 3 + 1][j * 8 + 6] - '0');
                if (x + y == z){
                    int tmp = (arr[i * 3 + 1][j * 8 + 6] == '.' ? 0 : 1);
                    for(int k = 1; k <= 5 + tmp; k++) {
                        arr[i * 3][j * 8 + k] = '*';
                        arr[i * 3 + 2][j * 8 + k] = '*';
                    }
                    arr[i * 3 + 1][j * 8] = '*';
                    arr[i * 3 + 1][j * 8 + 6 + tmp] = '*';
                } else {
                    for(int k = 0; k < 3; k++) arr[i * 3 + k][j * 8 + (3 - k)] = '/';
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 3 * N; i++){
            for(int j = 0; j < 8 * M; j++) sb.append(arr[i][j]);
            sb.append("\n");
        }
        System.out.print(sb);
    }    
}
