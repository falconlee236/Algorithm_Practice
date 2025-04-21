import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int day = Integer.parseInt(st.nextToken());
            int month = Integer.parseInt(st.nextToken());
            int year = Integer.parseInt(st.nextToken());
            if (day == 0 && month == 0 && year == 0) break;
            int[] days = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) days[2] = 29;
            int ans = 0;
            for(int i = 1; i < month; i++)ans += days[i];
            sb.append((ans + day) + "\n");
        }
        System.out.println(sb);
    }    
}
