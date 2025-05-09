import java.io.*;
import java.util.*;
class main{
    int[][] score = new int[11][11];
    boolean[] visit = new boolean[11];
    int ans;
    private void solve(int idx, int sum){
        if (idx == 11) {
            ans = Math.max(ans, sum);
            return;
        }
        for(int i = 0; i < 11; i++){
            if (visit[i] || score[idx][i] == 0) continue;
            visit[i] = true;
            solve(idx + 1, sum + score[idx][i]);
            visit[i] = false;
        }
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            for(int i = 0; i < 11; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j = 0; j < 11; j++) score[i][j] = Integer.parseInt(st.nextToken());
            }
            Arrays.fill(visit, false);
            ans = 0;
            solve(0, 0);
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}