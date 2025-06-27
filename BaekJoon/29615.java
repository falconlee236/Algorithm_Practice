import java.io.*;
import java.util.*;
class test1 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        HashMap<Integer, Boolean> mp = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++) mp.put(Integer.parseInt(st.nextToken()), false);
        for(int i = 0; i < M; i++){
            if (mp.containsKey(arr[i])) mp.put(arr[i], true);
        }
        int ans = 0;
        for(int x : mp.keySet()) {
            if (!mp.get(x)) ans++;
        }
        System.out.println(ans);
    }     
}
