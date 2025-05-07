import java.io.*;
import java.util.*;
class main {
    public static void main (String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), ans = 0, height = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            height = Math.min(height + 1, Integer.parseInt(st.nextToken()));
            ans = Math.max(ans, height);
        }
        System.out.println(ans);
    }
}