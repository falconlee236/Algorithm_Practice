import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        int mx = -1, ans = 0;
        for(int i = N - 1; i >= 0; i--){
            mx = Math.max(mx, arr[i]);
            ans = Math.max(ans, mx - arr[i]);
        }
        System.out.println(ans);
    }    
}
