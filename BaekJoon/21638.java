//https://www.acmicpc.net/problem/21638
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(st.nextToken()), y1 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int x2 = Integer.parseInt(st.nextToken()), y2 = Integer.parseInt(st.nextToken());
        if (x2 < 0 && y2 >= 10) System.out.println("A storm warning for tomorrow! Be careful and stay home if possible!");
        else if (x2 < x1) System.out.println("MCHS warns! Low temperature is expected tomorrow.");
        else if (y1 < y2) System.out.println("MCHS warns! Strong wind is expected tomorrow.");
        else System.out.println("No message");
    }
}