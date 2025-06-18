import java.util.*;
import java.io.*;
class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        Integer[] arr = new Integer[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr, Collections.reverseOrder());
        int res = 0, ans = 0;
        for(int i = 0; i < N; i++){
            if (res < M * K) {
                ans++;
                res += arr[i];
            }
        }
        System.out.println((res >= M * K ? ans : "STRESS"));
    }
}