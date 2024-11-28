package BaekJoon;
import java.util.*;
import java.io.*;

class main{
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        boolean[] visited = new boolean[N + 1];
        HashMap<String, Integer> mp = new HashMap<>();
        for(int i = 0; i < N; i++) mp.put(br.readLine(), i);
        int ans = 0, start = 0;
        for(int i = 0; i < N; i++){
            int idx = mp.get(br.readLine());
            visited[idx] = true;
            if (start == idx){
                while (visited[start]) start++;
            } else ans++;
        }
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}