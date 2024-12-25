package BaekJoon;
import java.io.*;
import java.util.*;

class main {
    int N, total, ans = Integer.MAX_VALUE;
    int[] arr;
    boolean[] group;
    ArrayList<ArrayList<Integer>> g;
    private void comb(int idx, int cnt, int sum){
        if (idx == N + 1){
            if (cnt >= N || cnt == 0) return;
            int a_cnt = 1, b_cnt = 1;
            boolean[] v = new boolean[N + 1];
            Queue<Integer> q = new LinkedList<>();
            for(int k = 1; k <= N; k++){
                if (!group[k]) continue;
                v[k] = true;
                q.offer(k);
                while(!q.isEmpty()){
                    int cur = q.poll();
                    for(int next : g.get(cur)){
                        if (v[next] || group[next] != group[k]) continue;
                        v[next] = true;
                        q.offer(next);
                        a_cnt++;
                    }
                }
                break;
            }
            for(int k = 1; k <= N; k++){
                if (group[k]) continue;
                v[k] = true;
                q.offer(k);
                while(!q.isEmpty()){
                    int cur = q.poll();
                    for(int next : g.get(cur)){
                        if (v[next] || group[next] != group[k]) continue;
                        v[next] = true;
                        q.offer(next);
                        b_cnt++;
                    }
                }
                break;
            }
            if (a_cnt == cnt && b_cnt == N - cnt) ans = Math.min(ans, Math.abs(sum - (total - sum)));
            return;
        }
        group[idx] = true;
        comb(idx + 1, cnt + 1, sum + arr[idx]);
        group[idx] = false;
        comb(idx + 1, cnt, sum);
    }

    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        g = new ArrayList<>(N + 1);
        for(int i = 0; i <= N; i++) g.add(new ArrayList<Integer>());
        arr = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            total += arr[i];
        }
        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            while (T-->0) g.get(i).add(Integer.parseInt(st.nextToken()));
        }
        group = new boolean[N + 1];
        comb(1, 0, 0);
        System.out.println((ans == Integer.MAX_VALUE ? -1 : ans));

    }
    public static void main(String[] args) throws Exception {
        new main().solution();
    }    
}