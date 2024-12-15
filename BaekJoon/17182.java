package BaekJoon;
import java.io.*;
import java.util.*;

class main {
    int N, K, ans;
    int[][] g;
    boolean[] v;
    private void solve(int node, int cnt, int cost){
        if (cnt == N){
            ans = Math.min(ans, cost);
            return;
        }
        for(int i = 0; i < N; i++){
            if (v[i]) continue;
            v[i] = true;
            solve(i, cnt + 1, cost + g[node][i]);
            v[i] = false;
        }
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        g = new int[N][N];
        v = new boolean[N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) g[i][j] = Integer.parseInt(st.nextToken());
        }
        for(int k = 0; k < N; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
            }
        }
        ans = Integer.MAX_VALUE;
        v[K] = true;
        solve(K, 1, 0);
        System.out.println(ans);
    }

    public static void main(String[] args) throws Exception {
        new main().solution();
    }
}

// 3 0
// 0 1 1
// 1 0 29
// 28 29 0

// import java.io.*;
// import java.util.*;

// class main {
//     int N, K, ans;
//     int[][] g;
//     private void solve(int node, int visit, int cost, int pprev, int prev){
//         if (cost >= ans) return;
//         if (visit == (1 << N) - 1){
//             ans = cost;
//             return;
//         }
        
//         for(int i = 0; i < N; i++){
//             if (node == i || (pprev == node && prev == i)) continue;
//             solve(i, visit | (1 << i), cost + g[node][i], prev, node);
//         }
//     }

//     private void solution() throws Exception {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringTokenizer st = new StringTokenizer(br.readLine());
//         N = Integer.parseInt(st.nextToken());
//         K = Integer.parseInt(st.nextToken());
//         g = new int[N][N];
//         for(int i = 0; i < N; i++){
//             st = new StringTokenizer(br.readLine());
//             for(int j = 0; j < N; j++) g[i][j] = Integer.parseInt(st.nextToken());
//         }
//         ans = 20000;
//         solve(K, (1 << K), 0, -1, -1);
//         System.out.println(ans);
//     }

//     public static void main(String[] args) throws Exception {
//         new main().solution();
//     }
    
// }

// // 3 0
// // 0 1 1
// // 1 0 29
// // 28 29 0