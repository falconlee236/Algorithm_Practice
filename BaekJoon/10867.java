package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        Set<Integer> s = new HashSet<>();
        for(int i = 0; i < N; i++) s.add(Integer.parseInt(st.nextToken()));
        List<Integer> lst = new ArrayList<>(s);
        Collections.sort(lst);
        for(int x : lst) sb.append(x + " ");
        System.out.println(sb);
    }
}