package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N], tap = new int[M];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        for(int i = N - 1; i >= 0; i--){
            int tmp = tap[0], idx = 0;
            for(int j = 1; j < M; j++){
                if (tmp > tap[j]){
                    idx = j;
                    tmp = tap[j];
                }
            }
            tap[idx] += arr[i];
        }
        int ans = 0;
        for(int x : tap) ans = Math.max(ans, x);
        System.out.println(ans);
    }
}






/*
 * 
 * 이진수의 핵심 -> 2^k > 2^(k-1) + 2^(k - 2) .... + 2^0
 */