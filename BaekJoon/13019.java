import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine(), B = br.readLine();
        int a = A.length() - 1, b = B.length() - 1, ans = 0;
        char[] a_arr = A.toCharArray(), b_arr = B.toCharArray();
        Arrays.sort(a_arr);
        Arrays.sort(b_arr);
        String C = new String(a_arr);
        if (!C.equals(new String(b_arr))) {
            System.out.println(-1);
            return;
        }
        while (a >= 0){
            if (A.charAt(a) == B.charAt(b)) b--;
            else ans++;
            a--;
        }
        System.out.println(ans);
    }    
}