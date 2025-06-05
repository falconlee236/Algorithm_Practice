import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String L = st.nextToken(), R = st.nextToken();
        if (L.length() != R.length()) System.out.println(0);
        else {
            int ans = 0;
            for(int i = 0; i < L.length(); i++){
                if (L.charAt(i) != R.charAt(i)) break;
                if (L.charAt(i) == '8' && L.charAt(i) == R.charAt(i)) ans++;
            }
            System.out.println(ans);
        }
    }
}