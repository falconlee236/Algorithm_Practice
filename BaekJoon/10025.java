package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken()), mx = 0;
        int[] arr = new int[1000001];
        long res = 0, ans = 0;
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            mx = Math.max(mx, b);
            arr[b] = a;
        }
        ans = res;
        for(int i = 0; i <= Math.min(K, mx); i++) res += arr[i];
        for(int i = 1; i <= mx; i++){
            if (i + K <= mx) res += arr[i + K];
            if (i - K - 1 >= 0) res -= arr[i - K - 1];
            ans = Math.max(ans, res);
        }
        System.out.println(ans);
    }
}
//   5 2         4                    10
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
// o x x x
// x o x x x
// x x o x x x 
// x x x o x x x
//   x x x o x x x
//     x x x o x x x
//       x x x o x x x
//         x x x o x x x
