import java.io.*;
import java.util.*;
class main {
    int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    int[][] arr;
    boolean[][] visited;
    int ans = Integer.MAX_VALUE;
    private void solve(int x, int y, int cost, int dist){
        if (cost == 3) {
            ans = Math.min(ans, dist);
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || arr[nx][ny] == -1) continue;
            visited[nx][ny] = true;
            solve(nx, ny, cost + arr[nx][ny], dist + 1);
            visited[nx][ny] = false;
        }
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = new int[5][5];
        visited = new boolean[5][5];
        StringTokenizer st;
        for(int i = 0; i < 5; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 5; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
        visited[x][y] = true;
        solve(x, y, 0, 0);
        System.out.println((ans == Integer.MAX_VALUE ? -1 : ans));
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}

// https://www.acmicpc.net/problem/26170
// dfs