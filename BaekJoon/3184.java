package BaekJoon;
import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int R = Integer.parseInt(line[0]);
        int C = Integer.parseInt(line[1]);
        int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        char[][] arr = new char[R][C];
        boolean[][] v = new boolean[R][C];
        for(int i = 0; i < R; i++){
            String s = br.readLine();
            for(int j = 0; j < C; j++) arr[i][j] = s.charAt(j);
        }
        int s = 0, w = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if (v[i][j] || arr[i][j] == '#') continue;
                Queue<int[]> q = new LinkedList<>();
                q.offer(new int[]{i, j});
                v[i][j] = true;
                int tmp_s = 0, tmp_w = 0;
                while (!q.isEmpty()){
                    int[] cur = q.poll();
                    if (arr[cur[0]][cur[1]] == 'o') tmp_s++;
                    else if (arr[cur[0]][cur[1]] == 'v') tmp_w++;
                    for(int k = 0; k < 4; k++){
                        int nx = cur[0] + dx[k], ny = cur[1] + dy[k];
                        if (nx < 0 || nx >= R || ny < 0 || ny >= C || v[nx][ny] || arr[nx][ny] == '#') continue;
                        q.offer(new int[]{nx, ny});
                        v[nx][ny] = true;
                    }
                }
                if (tmp_s > tmp_w) s += tmp_s;
                else w += tmp_w;
            }
        }
        System.out.println(s + " " + w);
    }    
}