package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), total = 0, ans = Integer.MAX_VALUE;
        int[][] arr = new int[N][N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                total += arr[i][j];
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int x = i, y = j;
                for(int d1 = 1; d1 <= N; d1++){
                    for(int d2 = 1; d2 <= N; d2++){
                        if (
                            !(x + d1 >= 0 && x + d1 < N && y - d1 >= 0 && y - d1 < N &&
                            x + d2 >= 0 && x + d2 < N && y + d2 >= 0 && y + d2 < N &&
                            x + d1 + d2 >= 0 && x + d1 + d2 < N && y - d1 + d2 >= 0 && y - d1 + d2 < N)
                        ) continue;
                        int one = 0, two = 0, three = 0, four = 0, mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
                        // 1
                        for(int d = 0; d <= d1; d++){
                            int nx = x + d, ny = y - d;
                            for(int t = 1; nx - t >= 0; t++) one += arr[nx - t][ny];
                        }
                        for(int a = 0; a < x + d1; a++){
                            for(int b = 0; b < y - d1; b++){
                                if (a < 0 || a >= N || b < 0 || b >= N) continue;
                                one += arr[a][b];
                            }
                        }
                        mx = Math.max(one, mx);
                        mn = Math.min(one, mn);
                        // 2
                        for(int d = 0; d <= d2; d++){
                            int nx = x + d, ny = y + d;
                            for(int t = 1; ny + t < N; t++) two += arr[nx][ny + t];
                        }
                        for(int a = x - 1; a >= 0; a--){
                            for(int b = y + 1; b < N; b++){
                                if (a < 0 || a >= N || b < 0 || b >= N) continue;
                                two += arr[a][b];
                            }
                        }
                        mx = Math.max(two, mx);
                        mn = Math.min(two, mn);
                        // 3
                        for(int d = 0; d <= d2; d++){
                            int nx = x + d1 + d, ny = y - d1 + d;
                            for(int t = 1; ny - t >= 0; t++) three += arr[nx][ny - t];
                        }
                        for(int a = N - 1; a > x + d1 + d2; a--){
                            for(int b = 0; b < y - d1 + d2; b++){
                                if (a < 0 || a >= N || b < 0 || b >= N) continue;
                                three += arr[a][b];
                            }
                        }
                        mx = Math.max(three, mx);
                        mn = Math.min(three, mn);
                        // 4
                        for(int d = 0; d <= d1; d++){
                            int nx = x + d2 + d, ny = y + d2 - d;
                            for(int t = 1; nx + t < N; t++) four += arr[nx + t][ny];
                        }
                        for(int a = N - 1; a > x + d2; a--){
                            for(int b = N - 1; b > y + d2; b--){
                                if (a < 0 || a >= N || b < 0 || b >= N) continue;
                                four += arr[a][b];
                            }
                        }
                        mx = Math.max(four, mx);
                        mn = Math.min(four, mn);
                        int five = total - (one + two + three + four);
                        mx = Math.max(five, mx);
                        mn = Math.min(five, mn);
                        ans = Math.min(ans, mx - mn);
                    }
                }
            }
        }
        System.out.println(ans);
    }
}