package BaekJoon;
import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, X, S, T, ans = -1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());
            if (S + T <= X) ans = Math.max(ans, S);
        }
        System.out.println(ans);
    }
}