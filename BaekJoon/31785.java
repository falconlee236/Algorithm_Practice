import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int Q = Integer.parseInt(br.readLine());
        int[] lst = new int[500001];
        int start = 1, end = 1;
        while (Q-->0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            if (type == 1){
                int num = Integer.parseInt(st.nextToken());
                lst[end] = lst[end - 1] + num;
                end++;
            } else {
                int mid = (start + end) / 2;
                int front = lst[mid - 1] - lst[start - 1], back = lst[end - 1] - lst[mid - 1];
                if (front <= back){
                    start = mid;
                    sb.append(front + "\n");
                } else {
                    end = mid;
                    sb.append(back + "\n");
                }
            }
        }
        for(int i = start; i < end; i++) sb.append((lst[i] - lst[i - 1]) + " ");
        System.out.println(sb);
    }
}