import java.util.*;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N], dp = new int[N];
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        for(int i = 0; i < N; i++){
            dp[i] = arr[i];
            int tmp = 0;
            for(int j = i - 1; j >= 0; j--){
                if (arr[i] < arr[j]) tmp = Math.max(dp[j], tmp);
            }
            dp[i] += tmp;
        }
        int ans = 0;
        for (int i : dp) ans = Math.max(i, ans);
        System.out.println(ans);
    }    
}
