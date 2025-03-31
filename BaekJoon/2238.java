import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int U = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken());
        String[] lst = new String[U + 1];
        int[] arr = new int[U + 1];
        while (N-->0){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            int num = Integer.parseInt(st.nextToken());
            if (arr[num] == 0) lst[num] = str;
            arr[num]++;
        }
        int mn = Integer.MAX_VALUE;
        for(int i = 1; i <= U; i++) {
            if (arr[i] == 0) continue;
            mn = Math.min(mn, arr[i]);
        }
         for(int i = 1; i <= U; i++) {
            if (arr[i] == mn) {
                System.out.println(lst[i] + " " + i);
                return;
            }
         }
    }
}