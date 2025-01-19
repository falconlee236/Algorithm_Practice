package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int ans = arr[N - 1];
        for(int i = 0; i < N / 2; i++) ans += (arr[N - i - 2] - arr[i]);
        System.out.println(ans);
    }
}


/*
 * 
 * 
 * 1 2 3 4 5 6 
 * 6 1 5 2 4 3
 * 6 + 0 + 4 + 0 + 2 + 0
 * 
 * 1 2 3 4 5 6 7
 * 7 1 6 2 5 3 4
 */