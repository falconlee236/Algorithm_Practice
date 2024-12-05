import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long[] arr = new long[N];
        st = new StringTokenizer(br.readLine());
        long ans = 0;
        for(int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
            ans += arr[i];
        }
        Arrays.sort(arr);
        long tmp = ans;
        ans = Math.max(ans, tmp - (arr[N - 1] + arr[N - 2]) + (arr[N - 1] * arr[N - 2] * 2));
        ans = Math.max(ans, tmp - (arr[0] + arr[1]) + (arr[0] * arr[1] * 2));
        System.out.println(ans);
    }
}