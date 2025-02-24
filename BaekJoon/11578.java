package BaekJoon;
import java.util.*;
import java.io.*;
class main {
    boolean[] teams;
    int[] problems;
    int ans = Integer.MAX_VALUE, N, M;
    private void solve(int idx, int state) {
        if (idx == M){
            if (state != (1 << N) - 1) return;
            int tmp = 0;
            for(boolean b : teams){
                if (b) tmp++;
            }
            ans = Math.min(ans, tmp);
            return;
        }
        teams[idx] = true;
        solve(idx + 1, state | problems[idx]);
        teams[idx] = false;
        solve(idx + 1, state);
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        teams = new boolean[M];
        problems = new int[M];
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            for(int j = 0; j < T; j++) problems[i] |= (1 << (Integer.parseInt(st.nextToken()) - 1));
        }
        solve(0, 0);
        System.out.println((ans == Integer.MAX_VALUE ? -1 : ans));
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }    
}