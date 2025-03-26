import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), use = Integer.parseInt(st.nextToken());
        int[][] arr = new int[N][N], new_arr = new int[N][N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        while (true) {
            for(int i = 0; i < N; i++){
                for (int j = 0; j < N; j++) new_arr[i][j] = arr[i][j];
            }
            for(int i = 0; i < N; i++){
                int tmp  = 0;
                for(int j = 0; j < N; j++) tmp += new_arr[i][j];
                if (use == 1 && tmp > N / 2) {
                    for(int j = 0; j < N; j++) new_arr[i][j] = 1;
                } else if (use == 0 && tmp <= N / 2){
                    for(int j = 0; j < N; j++) new_arr[i][j] = 0;
                }
            }
            for(int i = 0; i < N; i++){
                int tmp  = 0;
                for(int j = 0; j < N; j++) tmp += new_arr[j][i];
                if (use == 1 && tmp > N / 2) {
                    for(int j = 0; j < N; j++) new_arr[j][i] = 1;
                } else if (use == 0  && tmp <= N / 2){
                    for(int j = 0; j < N; j++) new_arr[j][i] = 0;
                }
            }
            boolean flag = true;
            for(int i = 0; i < N; i++){
                for (int j = 0; j < N; j++) {
                    if (new_arr[i][j] != arr[i][j]) flag = false;
                    arr[i][j] = new_arr[i][j];
                }
            }
            if (flag) break;
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans += arr[i][j];
            }
        }
        if (use == 0) System.out.println((ans == 0 ? 1 : 0));
        else System.out.println((ans == N * N ? 1 : 0));    
    }
}
