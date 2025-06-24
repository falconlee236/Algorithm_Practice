import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), mn = -1;
        int[] arr = new int[81];
        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                for(int k = 1; k <= c; k++) {
                    arr[i + j + k]++;
                    mn = Math.max(mn, arr[i + j + k]);
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i <= 80; i++){
            if (mn == arr[i]) ans = Math.min(ans, i);
        }
        System.out.println(ans);
    }
}