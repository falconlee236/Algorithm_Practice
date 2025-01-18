import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        int mx = 0;
        long ans = 0;
        for(int i = 0 ; i < N; i++){
            arr[i] = Integer.parseInt(br.readLine());
            mx = Math.max(mx, arr[i]);
        }
        for(int i = 1; i <= mx; i++){
            long tmp = 0;
            for(int j = 0; j < N; j++) {
                long cut = arr[j] / i - (arr[j] % i == 0 ? 1 : 0), cnt = arr[j] / i;
                tmp += Math.max(0, cnt * i * W - C * cut);
            }
            ans = Math.max(ans, tmp);
        }
        System.out.println(ans);
    }
}
/*
 * 
 * 5 <- 1   개수 5개, 자른횟수 4회   5 ->   1 4 -> 1 1 3 -> 1 1 1 2 -> 1 1 1 1
 * 5 <- 2   개수 2개, 자른횟수 2회   5->  2 3 - > 2 2 1
 * 5 <- 3   개수 1개, 자른 횟수 1회
 * 5 <- 4   개수 1개, 자른 횟수 1회
 * 5 <- 5   개수 1개, 자른 횟수 0회  cnt = arr[j] / i 자른 횟수 arr[j] / i - (arr[j] % i == 0)
 * 5 <- 6   개수 0개, 자른횟수 0회
 */