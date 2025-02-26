import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken()), S = Integer.parseInt(st.nextToken());
        System.out.println((S == 0 && (T >= 12 && T <= 16) ? 320 : 280));
    }    
}
