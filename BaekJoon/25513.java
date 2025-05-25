import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] arr = new int[5][5];
        StringTokenizer st;
        for(int i = 0 ; i < 5; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 5; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), ans = 0;
        int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        for(int t = 1, start_x = x, start_y = y; t <= 6; t++){
            boolean[][] visited = new boolean[5][5];
            Queue<int[]> q = new LinkedList<>();
            visited[start_x][start_y] = true;
            q.offer(new int[]{start_x, start_y, 0});
            boolean flag = false;
            while (!q.isEmpty()){
                int[] cur = q.poll();
                if (arr[cur[0]][cur[1]] == t) {
                    ans += cur[2];
                    flag = true;
                    start_x = cur[0];
                    start_y = cur[1];
                    break;
                }
                for(int i = 0; i < 4; i++){
                    int nx = cur[0] + dx[i], ny = cur[1] + dy[i];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || arr[nx][ny] == -1) continue;
                    visited[nx][ny] = true;
                    q.offer(new int[]{nx, ny, cur[2] + 1});
                }
            }
            if (!flag) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(ans);
    }    
}