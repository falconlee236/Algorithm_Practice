import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][M];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        int X = Integer.parseInt(br.readLine());
        if (arr[0][0] != arr[N - 1][M - 1]) {
            System.out.println("DEAD");
            return;
        }
        Queue<int[]> q = new LinkedList<>();
        boolean[][] v = new boolean[N][M];
        q.offer(new int[]{0, 0});
        v[0][0] = true;
        while (!q.isEmpty()){
            int[] cur = q.poll();
            if (cur[0] == N - 1 && cur[1] == M - 1) {
                System.out.println("ALIVE");
                return;
            }
            for(int i = -X; i <= X; i++){
                for(int j = -X; j <= X; j++){
                    int nx = cur[0] + i, ny = cur[1] + j;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || v[nx][ny] || arr[nx][ny] != arr[0][0] || Math.abs(cur[0] - nx) + Math.abs(cur[1] - ny) > X) continue;
                    q.offer(new int[]{nx, ny});
                    v[nx][ny] = true;
                }
            }
        }
        System.out.println("DEAD");
    }
}
