package BaekJoon;
import java.io.*;
import java.util.*;
class main {
   public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken()), H = Integer.parseInt(st.nextToken()), total = 0, cnt = 0;
        int[][][] arr = new int[N][M][H], time = new int[N][M][H];
        boolean[][][] visited = new boolean[N][M][H];
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0; i < H; i++){
            for(int j = 0; j < N; j++){
                st = new StringTokenizer(br.readLine());
                for(int k = 0; k < M; k++) {
                    arr[j][k][i] = Integer.parseInt(st.nextToken());
                    if (arr[j][k][i] != -1) total++;
                    if (arr[j][k][i] == 1) {
                        cnt++;
                        visited[j][k][i] = true;
                        q.offer(new int[]{j, k, i});
                    }
                }
            }
        }
        int[] dx = {0, 1, 0, -1, 0, 0}, dy = {1, 0, -1, 0, 0, 0}, dz = {0, 0, 0, 0, 1, -1};
        int ans = 0;
        while (!q.isEmpty()){
            int[] cur = q.poll();
            for(int i = 0; i < 6; i++){
                int nx = cur[0] + dx[i], ny = cur[1] + dy[i], nz = cur[2] + dz[i];
                if (!(nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H) || visited[nx][ny][nz]|| arr[nx][ny][nz] == -1) continue;
                time[nx][ny][nz] = time[cur[0]][cur[1]][cur[2]] + 1;
                ans = Math.max(ans, time[nx][ny][nz]);
                visited[nx][ny][nz] = true;
                cnt++;
                q.offer(new int[]{nx, ny, nz});
            }
        }
        System.out.println((cnt != total ? -1 : ans));
   }
}
