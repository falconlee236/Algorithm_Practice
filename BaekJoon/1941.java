package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    char[][] arr = new char[5][5];
    int[] lst = new int[7], dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    int ans;
    private void comb(int idx, int cnt, int res){
        if (cnt == 7) {
            if (res < 4) return;
            boolean[][] v = new boolean[5][5], check = new boolean[5][5];
            Queue<int[]> q = new ArrayDeque<>();
            for(int x : lst) check[x / 5][x % 5] = true;
            q.offer(new int[]{lst[0] / 5, lst[0] % 5});
            v[lst[0] / 5][lst[0] % 5] = true;
            while (!q.isEmpty()){
                int[] cur = q.poll();
                for(int i = 0; i < 4; i++){
                    int nx = cur[0] + dx[i], ny = cur[1] + dy[i];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || v[nx][ny] || !check[nx][ny]) continue;
                    v[nx][ny] = true;
                    q.offer(new int[]{nx, ny});
                }
            }
            for(int x : lst) {
                if (!v[x / 5][x % 5]) return;
            }
            ans++;
            return;
        }
        for(int i = idx; i < 25; i++){
            lst[cnt] = i;
            comb(i + 1, cnt + 1, res + (arr[i / 5][i % 5] == 'S' ? 1 : 0));
        }
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 5; i++){
            String line = br.readLine();
            for(int j = 0; j < 5; j++) arr[i][j] = line.charAt(j);
        }
        comb(0, 0, 0);
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}