import java.io.*;
import java.util.*;
class main {
    String str;
    int N, M, ans;
    char[][] arr;
    int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1}, dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    private void solve(int x, int y, int cnt, int pos){
        if (cnt == str.length()){
            ans = 1;
            return;
        }
        if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] != str.charAt(cnt)) return;
        solve(x + dx[pos], y + dy[pos], cnt + 1, pos);
    }

    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new char[N][M];
        for(int i = 0; i < N; i++){
            String s = br.readLine();
            for(int j = 0; j < M; j++) arr[i][j] = s.charAt(j);
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) {
                for(int t = 0; t < 8; t++) solve(i, j, 0, t);
            }
        }
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}
