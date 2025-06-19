import java.io.*;
import java.util.*;
public class test6 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), ms = Integer.MIN_VALUE, me = Integer.MAX_VALUE;
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
            me = Math.min(me, e);
            ms = Math.max(ms, s);
        }
        System.out.println(Math.max(ms - me, 0));
    }
}