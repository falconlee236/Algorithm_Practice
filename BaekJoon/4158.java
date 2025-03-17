import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), ans = 0;
            if (N == 0 && M == 0) break;
            HashSet<Integer> s = new HashSet<>();
            while (N-->0) s.add(Integer.parseInt(br.readLine()));
            while (M-->0){
                if (s.contains(Integer.parseInt(br.readLine()))) ans++;
            }
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }    
}
