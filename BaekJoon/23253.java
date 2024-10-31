import java.io.*;
import java.util.*;

class main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for(int i = 0; i < m; i++){
            int k = Integer.parseInt(br.readLine());
            int prev = Integer.MAX_VALUE;
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < k; j++){
                int cur = Integer.parseInt(st.nextToken());
                if (prev < cur){
                    System.out.println("No");
                    return;
                }
                prev = cur;
            }
        }
        System.out.println("Yes");
    }
}