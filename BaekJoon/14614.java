import java.io.*;
import java.util.*;
public class test3 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        String c = st.nextToken();
        System.out.print(((c.charAt(c.length() - 1) - '0') % 2 == 0 ? a : a ^ b));
    }
}
// https://www.acmicpc.net/problem/14614