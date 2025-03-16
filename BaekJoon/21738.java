package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), S = Integer.parseInt(st.nextToken()), P = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] g = new ArrayList[N + 1];
        int[] visit = new int[N + 1];
        for(int i = 1; i <= N; i++) g[i] = new ArrayList<>();
        for(int i = 0; i < N - 1; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
            g[u].add(v);
            g[v].add(u);
        }
        Queue<Integer> q = new LinkedList<>();
        q.offer(P);
        visit[P] = 1;
        int cnt = 0;
        while (!q.isEmpty() && cnt < 2){
            int cur = q.poll();
            if (1 <= cur && cur <= S && cnt < 2) {
                N -= (visit[cur] - 1);
                cnt++;
            }
            for (int node : g[cur]) {
                if (visit[node] > 0) continue;
                visit[node] = visit[cur] + 1;
                q.offer(node);
            }
        }
        System.out.println(N - 1);
    }    
}