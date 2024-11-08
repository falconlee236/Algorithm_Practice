package BaekJoon;
import java.util.*;
import java.io.*;

class main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int i = 0; i < n + 1; i++) arr.add(new ArrayList<Integer>());
        
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
        }
        Queue<Integer> q = new LinkedList<>();
        int[] visited = new int[n + 1];
        visited[s] = 1;
        q.offer(s);
        while (!q.isEmpty()){
            int p = q.poll();
            if (p == e){
                System.out.println(visited[p] - 1);
                return;
            }
            if (p > 0 && visited[p - 1] == 0) {
                visited[p - 1] = visited[p] + 1;
                q.offer(p - 1);
            }
            if (p < n && visited[p + 1] == 0) {
                visited[p + 1] = visited[p] + 1;
                q.offer(p + 1);
            }
            for(int next : arr.get(p)){
                if (visited[next] == 0){
                    visited[next] = visited[p] + 1;
                    q.offer(next);
                }
            }
        }
    }
}
