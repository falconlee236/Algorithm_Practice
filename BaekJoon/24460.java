import java.io.*;
import java.util.*;
class main {
    int N;
    int[][] arr;
    private int solve(int x, int y, int n){
        if (n == 1) return arr[x][y];
        int[] tmp = {
            solve(x, y, n / 2),
            solve(x + (n / 2), y, n / 2),
            solve(x, y + (n / 2), n / 2),
            solve(x + (n / 2), y + (n / 2), n / 2)
        };
        Arrays.sort(tmp);
        return tmp[1];
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        System.out.println(solve(0, 0, N));
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }    
}