package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        for (int t = 1;; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            if (L == 0 && P == 0 && V == 0) break;
            sb.append("Case ").append(t).append(": " + ((V / P) * L + ((V % P < L ? V % P : L))) + "\n");
        }
        System.out.print(sb);
    }
}
/*
 * l  p  v
 * 5 11 21 -> 10
 * 
 */