package BaekJoon;
import java.util.*;
import java.io.*;

class main {
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Integer>> g = new ArrayList<>(n + 1);
        for(int i = 0; i < n + 1; i++) g.add(new ArrayList<Integer>());
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            g.get(a).add(b);
            g.get(b).add(a);
        }
        int mn = Integer.MAX_VALUE, ans = 5000;
        for(int i = 1; i <= n; i++){
            Queue<Integer> q = new LinkedList<>();
            int[] visited = new int[n + 1];
            q.offer(i);
            while (!q.isEmpty()) {
                int cur = q.poll();
                for(int next : g.get(cur)){
                    if (visited[next] > 0) continue;
                    visited[next] = visited[cur] + 1;
                    q.offer(next);
                }
            }
            int tmp = 0;
            for(int j = 1; j <= n; j++) {
                if (j == i) continue;
                tmp += visited[j];
            }
            if (tmp < mn){
                ans = i;
                mn = tmp;
            }
        }
        System.out.println(ans);
    }


    public static void main(String[] args) throws Exception{
        new main().solution();
    }    
}