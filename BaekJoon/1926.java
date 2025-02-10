import java.io.*;
import java.util.*;
class main {
    int ans, N, M, tmp;
    int[][] arr;
    boolean[][] v;
    int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    private void solve(int x, int y){
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || v[nx][ny] || arr[nx][ny] == 0) continue;
            v[nx][ny] = true;
            tmp++;
            solve(nx, ny);
        }
    }

    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        v = new boolean[N][M];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if (v[i][j] || arr[i][j] == 0) continue;
                v[i][j] = true;
                tmp = 1;
                solve(i, j);
                ans = Math.max(ans, tmp);
                cnt++;
            }
        }
        System.out.println(cnt + "\n" + ans);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}
