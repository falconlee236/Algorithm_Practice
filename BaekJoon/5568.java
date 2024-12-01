import java.io.*;
import java.util.HashSet;

class main {
    private int N;
    private String[] arr;
    private HashSet<String> set;
    private boolean[] visited;

    private void solve(int cnt, int idx, String s){
        if (cnt == 0) {
            set.add(s);
            return;
        }
        for(int i = 0; i < N; i++){
            if (visited[i]) continue;
            visited[i] = true;
            solve(cnt - 1, idx + 1, s + arr[i]);
            visited[i] = false;
        }
    }

    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());
        arr = new String[N];
        visited = new boolean[N];
        set = new HashSet<>();
        for(int i = 0; i < N; i++) arr[i] = br.readLine();
        solve(K, 0, "");
        System.out.println(set.size());
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}
