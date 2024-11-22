import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), ans = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) ans += Math.abs(Integer.parseInt(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) ans += Math.abs(Integer.parseInt(st.nextToken()));
        System.out.println(ans);
    }
}