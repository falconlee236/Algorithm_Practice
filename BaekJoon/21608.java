package BaekJoon;
import java.util.*;
import java.io.*;

class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] arr = new int[n][n];
        int[][] input = new int[n * n][5];
        int[] dx = { 0, 1, 0, -1 }, dy = { 1, 0, -1, 0 };
        for(int t = 0; t < n * n; t++){
            int[][] first = new int[n][n];
            int[][] second = new int[n][n];
            st = new StringTokenizer(br.readLine());
            input[t][4] = Integer.parseInt(st.nextToken());
            for(int i = 0; i < 4; i++) input[t][i] = Integer.parseInt(st.nextToken());
            int mx_first = 0, mx_second = 0, first_x = -1, first_y = -1, second_x = -1, second_y = -1, third_x = -1, third_y = -1, cnt_first = 0, cnt_second = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (arr[i][j] > 0) continue;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if (nx < 0 || nx >= n || ny < 0  || ny >= n) continue;
                        if (arr[nx][ny] == 0) second[i][j]++;
                        if (arr[nx][ny] == input[t][0] || arr[nx][ny] == input[t][1] || arr[nx][ny] == input[t][2] || arr[nx][ny] == input[t][3]) {
                            first[i][j]++;
                            mx_first = Math.max(mx_first, first[i][j]);
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (arr[i][j] != 0) continue;
                    if (first[i][j] == mx_first){
                        cnt_first++;
                        first_x = i;
                        first_y = j;
                        mx_second = Math.max(mx_second, second[i][j]);
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (arr[i][j] != 0) continue;
                    if (second[i][j] == mx_second && first[i][j] == mx_first){
                        cnt_second++;
                        second_x = i;
                        second_y = j;
                    }
                    if (third_x == -1 && third_y == -1 && second[i][j] == mx_second && first[i][j] == mx_first){
                        third_x = i;
                        third_y = j;
                    }
                }
            }
            if (cnt_first == 1 && mx_first != 0){
                arr[first_x][first_y] = input[t][4];
                continue;
            }
            if (cnt_second == 1){
                arr[second_x][second_y] = input[t][4];
                continue;
            }
            arr[third_x][third_y] = input[t][4];
        }
        int ans = 0;
        for(int t = 0; t < n * n; t++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (arr[i][j] != input[t][4]) continue;
                    int cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if (nx < 0 || nx >= n || ny < 0  || ny >= n) continue;
                        if (arr[nx][ny] == input[t][0] || arr[nx][ny] == input[t][1] || arr[nx][ny] == input[t][2] || arr[nx][ny] == input[t][3])  cnt++;                        
                    }
                    ans += (cnt == 0 ? 0 : (int) Math.pow(10, cnt - 1));
                }
            }
        }
        System.out.println(ans);
    }
}