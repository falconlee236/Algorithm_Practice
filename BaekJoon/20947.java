package BaekJoon;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        char[][] arr = new char[N][N];
        for(int i = 0; i < N; i++){
            String s = br.readLine();
            for(int j = 0; j < N; j++) {
                arr[i][j] = s.charAt(j);
                if (arr[i][j] == '.') arr[i][j] = 'B';
            }
        }
        int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if (arr[i][j] != 'O') continue;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    while (0 <= nx && nx < N && 0 <= ny && ny < N){
                        if (arr[nx][ny] == 'B' || arr[nx][ny] == '.') arr[nx][ny] = '.';
                        else break;
                        nx += dx[k];
                        ny += dy[k];
                    }
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) sb.append(arr[i][j]);
            sb.append("\n");
        }
        System.out.print(sb);
    }
}