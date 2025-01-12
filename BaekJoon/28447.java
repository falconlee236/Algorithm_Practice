package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    int[][] arr;
    int[] lst;
    int N, K, ans = Integer.MIN_VALUE;
    private void solve(int idx, int cnt) {
        if (cnt == K){
            int tmp = 0;
            for(int i = 0; i < K; i++){
                for(int j = i + 1; j < K; j++) tmp += arr[lst[i]][lst[j]];
            }
            ans = Math.max(tmp, ans);
            return;
        }
        for(int i = idx; i < N; i++){
            lst[cnt] = i;
            solve(i + 1, cnt + 1);
        }
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N][N];
        lst = new int[K];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        solve(0, 0);
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}