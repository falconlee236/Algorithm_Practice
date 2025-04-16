import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) pq.offer(Integer.parseInt(st.nextToken()));
        long ans = 0;
        int T = 0, Q = 0;
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            T = Integer.parseInt(st.nextToken());
            Q = Integer.parseInt(st.nextToken());
            while (!pq.isEmpty() && ans < Q) ans += (pq.poll() + T);
        }
        while (!pq.isEmpty()) ans += (pq.poll() + T);
        System.out.println((ans < Q ? -1 : ans));
    }
}