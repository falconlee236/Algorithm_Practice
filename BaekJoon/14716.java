import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), ans = 0;
        int[][] arr = new int[N][M];
        boolean[][] visit = new boolean[N][M];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        Queue<int[]> q = new LinkedList<>();
        int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1}, dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if (arr[i][j] == 0 || visit[i][j]) continue;
                ans++;
                q.clear();
                visit[i][j] = true;
                q.offer(new int[]{i, j});
                while (!q.isEmpty()){
                    int[] cur = q.poll();
                    for(int t = 0; t < 8; t++){
                        int nx = cur[0] + dx[t], ny = cur[1] + dy[t];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || arr[nx][ny] == 0) continue;
                        visit[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }
        System.out.println(ans);
    }
}