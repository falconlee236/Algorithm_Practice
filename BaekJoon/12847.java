import java.io.*;
import java.util.*;

class main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long[] arr = new long[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) arr[i] = Long.parseLong(st.nextToken());
        long res = 0;
        for(int i = 0; i < m; i++) res += arr[i];
        long tmp = res;
        for(int i = 1; i < n - m; i++){
            tmp -= arr[i - 1];
            tmp += arr[i + m - 1];
            res = Math.max(res, tmp);
        }
        System.out.println(res);
    }
}