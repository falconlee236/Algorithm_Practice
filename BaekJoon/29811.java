package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int[] idx = new int[N + M + 1];
        PriorityQueue<int[]> pq1 = new PriorityQueue<>((a, b) -> {
            if (a[1] == b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });
        PriorityQueue<int[]> pq2 = new PriorityQueue<>((a, b) -> {
            if (a[1] == b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++) {
            int num = Integer.parseInt(st.nextToken());
            pq1.add(new int[]{i, num});
            idx[i] = num;
        }
        st = new StringTokenizer(br.readLine());
        for(int i = N + 1; i <= M + N; i++) {
            int num = Integer.parseInt(st.nextToken());
            pq2.add(new int[]{i, num});
            idx[i] = num;
        }
        int Q = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (Q-->0){
            st = new StringTokenizer(br.readLine());
            String query = st.nextToken();
            if (query.equals("U")){
                int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
                if (a > N) pq2.add(new int[]{a, b});
                else pq1.add(new int[]{a, b});
                idx[a] = b;
            } else {
                while (idx[pq1.peek()[0]] != pq1.peek()[1]) pq1.poll();
                while (idx[pq2.peek()[0]] != pq2.peek()[1]) pq2.poll();
                sb.append(pq1.peek()[0] + " " + pq2.peek()[0] + "\n");
            }
        }
        System.out.println(sb);
    }
}