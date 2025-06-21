import java.io.*;
import java.util.*;
public class test2 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        int one = 0, zero = 0, ans = 0;
        for(int i = 0; i < N; i++){
            if (arr[i] == 0) {
                if (i > 0 && arr[i] != arr[i - 1]) zero = 0;
                zero++;
                ans = Math.max(ans, zero + one);
            } else {
                if (i > 0 && arr[i] != arr[i - 1]) one = 0;
                one++;
                ans = Math.max(ans, zero + one);
            }
        }
        System.out.println(ans);
    }
}

// https://www.acmicpc.net/problem/32622