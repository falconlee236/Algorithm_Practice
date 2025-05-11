package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), Q = Integer.parseInt(st.nextToken());
        HashMap<Integer, Integer> mp = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for(int i = 0; i < N; i++){
            int key = Integer.parseInt(st.nextToken());
            arr[i] = key;
            mp.put(key, mp.containsKey(key) ? mp.get(key) + 1 : 1);
        }
        while (Q-->0){
            st = new StringTokenizer(br.readLine());
            int query = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
            if (query == 1){
                if (x == 0) sb.append((mp.containsKey(0) && N > 1 ? 1 : 0) + "\n");
                else {
                    boolean flag = false;
                    for(int i = 1; i * i <= x; i++){
                        if (x % i != 0) continue;
                        if ((i == x / i && mp.containsKey(i) && mp.get(i) > 1) || i != x / i && mp.containsKey(i) && mp.get(i) > 0 && mp.containsKey(x / i) && mp.get(x / i) > 0) flag = true;
                    }
                    sb.append((flag ? 1 : 0) + "\n");
                }
            } else {
                if (arr[x - 1] == 0) continue;
                mp.put(arr[x - 1], mp.get(arr[x - 1]) - 1);
                mp.put(0, mp.containsKey(0) ? mp.get(0) + 1 : 1);
                arr[x - 1] = 0;
            }
        }
        System.out.print(sb);
    }    
}