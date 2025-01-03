package BaekJoon;
import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Map<String, Integer> mp = new HashMap<>();
        for(int i = 0; i < N; i++){
            String s = st.nextToken();
            if (mp.get(s) == null) mp.put(s, 1);
            else mp.put(s, mp.get(s) + 1);
        }
        List<String> lst = new ArrayList<>();
        for (String key : mp.keySet()) {
            lst.add(key);
            if (mp.get(key) > 1) lst.add(key);
        }
        Set<Character> s = new TreeSet<>();
        for(int i = 0; i < lst.size(); i++){
            for(int j = 0; j < lst.size(); j++){
                if (i == j) continue;
                String a = lst.get(i), b = lst.get(j);
                if (a.charAt(0) > b.charAt(1)) s.add(a.charAt(0));
                else s.add(b.charAt(1));
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(s.size() + "\n");
        for (char c : s) sb.append(c + " ");
        System.out.print(sb);
    }
}



/*
 * AB CD
 * A C
 * B D
 * 
 * A, D, X
 * B, C, P
 * 
 * 
 * A A D
 * B B C
 * 
 * A A B C X
 * A A C D P
 */