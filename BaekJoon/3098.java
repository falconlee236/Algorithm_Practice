import java.io.*;
import java.util.*;
class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        HashSet<Integer>[] g = new HashSet[N + 1];
        HashSet<ArrayList<Integer>> s = new HashSet<>();
        for(int i = 0; i <= N; i++) g[i] = new HashSet<>();
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
            g[x].add(y);
            g[y].add(x);
            s.add(new ArrayList<>(Arrays.asList(Math.min(x, y), Math.max(x, y))));
        }
        StringBuilder sb = new StringBuilder();
        int ans = 0;
        while (s.size() != (N * (N - 1)) / 2) {
            int before = s.size();
            ans++;
            for(int i = 1; i <= N; i++){
                for(int x : g[i]){
                    for(int j : g[x]){
                        if (i == j) continue;
                        s.add(new ArrayList<>(Arrays.asList(Math.min(i, j), Math.max(i, j))));
                    }
                }
            }
            for(ArrayList<Integer> x : s){
                g[x.get(0)].add(x.get(1));
                g[x.get(1)].add(x.get(0));
            }
            sb.append((s.size() - before) + "\n");
        }
        System.out.println(ans);
        System.out.print(sb);
    }
}