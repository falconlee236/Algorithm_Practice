import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), ans = 0;
        for(int i = 0; i < N; i++){
            String line = br.readLine();
            int ok = 0;
            for(int j = 0; j < M; j++){
                if (line.charAt(j) == 'O') ok++;
            }
            if (ok > M / 2) ans++;
        }
        System.out.println(ans);
    }
}
