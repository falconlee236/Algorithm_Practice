import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken()), B = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken());
        ArrayList<Integer> x = new ArrayList<>(), y = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((first, second) -> {
            if (first[0] == second[0]) return first[1] - second[1];
            return first[0] - second[0];
        });
        int cnt = 1, time_a = 0, time_b = 0;
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            String c = st.nextToken();
            int m = Integer.parseInt(st.nextToken());
            if (c.equals("B")){
                if (time_a < t) time_a = t;
                while (m-->0) {
                    pq.offer(new int[]{time_a, 1});
                    time_a += A;
                }
            } else {
                if (time_b < t) time_b = t;
                while (m-->0) {
                    pq.offer(new int[]{time_b, 2});
                    time_b += B;
                }
            }
        }
        
        while (!pq.isEmpty()){
            int[] cur = pq.poll();
            if (cur[1] == 1) x.add(cnt++);
            else y.add(cnt++);
        }
        StringBuilder sb = new StringBuilder();
        sb.append(x.size() + "\n");
        for (int i : x) sb.append(i + " ");
        sb.append("\n");
        sb.append(y.size() + "\n");
        for (int i : y) sb.append(i + " ");
        sb.append("\n");
        System.out.print(sb);
    }
}
