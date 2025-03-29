package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    char[][] arr;
    int[][] point;
    int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    int N, M;
    StringBuilder sb = new StringBuilder();
    private void solve(int x, int y){
        if (x == point[1][0] && y == point[1][1]) {
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++) {
                    if (arr[i][j] == '+') sb.append(arr[i][j]);
                    else sb.append((arr[i][j] == '.' ? '@' : '.'));
                }
                sb.append("\n");
            }
            System.out.print(sb);
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != '.') continue;
            arr[nx][ny] = '@';
            solve(nx, ny);
            arr[nx][ny] = '.';
        }
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new char[N][M];
        point = new int[2][2];
        for(int i = 0, idx = 0; i < N; i++){
            String s = br.readLine();
            for(int j = 0; j < M; j++) {
                arr[i][j] = s.charAt(j);
                if ((i == 0 || j == 0 || i == N-1 || j == M-1) && arr[i][j] == '.') {
                    point[idx][0] = i;
                    point[idx][1] = j;
                    idx++;
                }
            }
        }
        arr[point[0][0]][point[0][1]] = '@';
        solve(point[0][0], point[0][1]);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}