import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine()), num = 0, ans = 0;
        int[][] arr = new int[N][3];
        int[] cnt = new int[N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());           
        }
        Arrays.sort(arr, (o1, o2) -> o1[0] - o2[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        PriorityQueue<int[]> lst = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
        for(int[] x : arr){
            while (!pq.isEmpty() && pq.peek()[1] < x[0]) lst.offer(pq.poll());
            int idx = lst.isEmpty() ? num++ : lst.poll()[2];
            cnt[idx]++;
            x[2] = idx;
            ans = Math.max(ans, idx);
            pq.offer(x);
        }
        sb.append((ans + 1) + "\n");
        for(int i = 0; i <= ans; i++) sb.append(cnt[i] + " ");
        System.out.print(sb);
    }
}

// 5
// 20 50
// 10 100
// 30 120
// 60 70
// 80 90
// 3
// 1 3 1


// 5
// 20 50
// 10 100
// 30 120
// 130 150
// 160 900
// 3
// 3 1 1