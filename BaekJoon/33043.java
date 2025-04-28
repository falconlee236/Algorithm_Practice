import java.io.*;
import java.util.*;
// https://www.acmicpc.net/problem/33043
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<String, Queue<Integer>> mp = new HashMap<>();
        int ans = 0xFFFFFF;
        for(int i = 0; i < N; i++){
            String key = st.nextToken();
            if (mp.containsKey(key)) mp.get(key).add(i);
            else {
                mp.put(key, new LinkedList<>());
                mp.get(key).add(i);
            }
            if (mp.containsKey(key) && mp.get(key).size() == 5){
                ans = Math.min(ans, i - mp.get(key).poll());
            }
        }
        System.out.println((ans == 0xFFFFFF ? -1 : ans));
    }    
}