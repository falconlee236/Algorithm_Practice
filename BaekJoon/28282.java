package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int X = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] tmp = new int[K + 1], arr = new int[X];
        for(int i = 0; i < X; i++) arr[i] = Integer.parseInt(st.nextToken());
        for(int i = 0; i < X; i++) tmp[Integer.parseInt(st.nextToken())]++;
        long ans = 0;
        for(int i = 0; i < X; i++) ans += (X - tmp[arr[i]]);
        System.out.println(ans);
    }
}