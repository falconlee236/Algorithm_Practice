import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long ans = 0, prev = 0, div = 1000000007;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N - 1; i++) {
            prev = ((prev + 1) * Long.parseLong(st.nextToken())) % div;
            ans = (ans + prev) % div;
        }
        System.out.println(ans);
    }
}