import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        HashMap<String, Integer> mp = new HashMap<>();
        String[] arr = new String[N];
        for(int i = 0; i < N; i++){
            String str = br.readLine();
            arr[i] = str;
            if (mp.containsKey(str)) mp.put(str, mp.get(str) + 1);
            else mp.put(str, 1);
        }
        Arrays.sort(arr);
        int cnt = -1;
        String ans = "";
        for(String key : arr) {
            if (cnt < mp.get(key)) {
                cnt = mp.get(key);
                ans = key;
            }
        }
        System.out.print(ans);
    }
}