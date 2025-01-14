package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int s = 0, e = N - 1, ans = 0;
        while (s < e) {
            if (arr[s] + arr[e] >= M) {
                ans++;
                e--;
            }
            s++;
        }
        System.out.println(ans);
    }
}

// 26091 - 6m 30s
/*
 * 3 3 5 5 6 7
 * 3 7
 * 5 6
 * 
 */