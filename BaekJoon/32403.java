package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int ans = 0;
        TreeSet<Integer> s = new TreeSet<>();
        for(int i = 1; i <= T; i++) {
            if (T % i == 0) s.add(i);
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            int num = Integer.parseInt(st.nextToken());
            int tmp = Integer.MAX_VALUE;
            if (s.ceiling(num) != null) tmp = Math.min(s.ceiling(num) - num, tmp);
            tmp = Math.min(num - s.floor(num), tmp);
            ans += tmp;
        }
        System.out.println(ans);
    }    
}