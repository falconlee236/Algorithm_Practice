import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] a = new int[10], b = new int[10];
        for(int i = 0; i < 10; i++) a[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 10; i++) b[i] = Integer.parseInt(st.nextToken());
        int s_a = 0, s_b = 0, last = 0;
        for(int i = 0; i < 10; i++){
            if (a[i] > b[i]) {
                s_a += 3;
                last = 1;
            } else if (a[i] < b[i]){
                s_b += 3;
                last = -1;
            } else {
                s_a++;
                s_b++;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(s_a + " " + s_b + "\n" + (s_a == s_b ? (last == 0 ? 'D' : (last == 1 ? 'A' : 'B')) : (s_a > s_b ? 'A' : 'B')));
        System.out.println(sb);
    }
}