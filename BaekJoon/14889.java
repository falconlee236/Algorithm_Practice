package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    int N, ans = Integer.MAX_VALUE;
    int[][] arr;
    boolean[] team;
    private void solve(int idx, int cnt){
        if (idx == N){
            if (cnt != N / 2) return;
            int x = 0, y = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if (team[i] && team[j]) x += arr[i][j];
                    if (!team[i] && !team[j]) y += arr[i][j];
                }
            }
            ans = Math.min(ans, Math.abs(x - y));
            return;
        }
        team[idx] = true;
        solve(idx + 1, cnt + 1);
        team[idx] = false;
        solve(idx + 1, cnt);
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        team = new boolean[N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        solve(0, 0);
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}

/*
 * 14889 -> 12m 00s solved
 */