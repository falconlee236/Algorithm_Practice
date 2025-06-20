import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long x = -1, y = -1;
        while(N-->0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken()), b = Long.parseLong(st.nextToken());
            x = Math.max(x, Math.min(a, b));
            y = Math.max(y, Math.max(a, b));
        }
        System.out.println(x * y);
    }
}
//https://www.acmicpc.net/problem/33520