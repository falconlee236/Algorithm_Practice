package BaekJoon;
import java.util.*;
import java.io.*;

class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int st_y = Integer.parseInt(st.nextToken());
        int st_m = Integer.parseInt(st.nextToken());
        int st_d = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int ed_y = Integer.parseInt(st.nextToken());
        int ed_m = Integer.parseInt(st.nextToken());
        int ed_d = Integer.parseInt(st.nextToken());
        int start = st_y * 360 + st_m * 30 + st_d, end = ed_y * 360 + ed_m * 30 + ed_d, ans = 0;
        for(int i = 1; i <= (end - start) / 360; i++) ans += ((i + 1) / 2 - 1) + 15;
        System.out.printf("%d %d\n%ddays\n", ans, ((end - start) / 360 < 3 ? ((end - start) / (30)) : 36), end - start);
    }
}
