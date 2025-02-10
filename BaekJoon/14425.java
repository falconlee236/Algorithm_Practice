import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), ans = 0;
        HashSet<String> s = new HashSet<>(N);
        while(N-->0) s.add(br.readLine());
        while(M-->0) {
            if (s.contains(br.readLine())) ans++;
        }
        System.out.println(ans);
    }
}