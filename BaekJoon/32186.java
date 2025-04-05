import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        long ans = 0;
        for(int i = 0; i < N / 2; i++){
            int dist = Math.abs(arr[i] - arr[N - i - 1]);
            if (dist == 0) continue;
            int Q = dist / K, R = dist % K;
            ans += Math.min(Q + R, Q + 1 + (K - R));
        }
        System.out.println(ans);
    }
}