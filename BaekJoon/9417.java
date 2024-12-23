package BaekJoon;
import java.io.*;
import java.util.*;

class main{
    private int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        while (N-->0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> lst = new ArrayList<>();
            int ans = 0;
            while (st.hasMoreTokens()) lst.add(Integer.parseInt(st.nextToken()));
            for(int i = 0; i < lst.size(); i++){
                for(int j = i + 1; j < lst.size(); j++) ans = Math.max(ans, gcd(Math.max(lst.get(i), lst.get(j)), Math.min(lst.get(i), lst.get(j))));
            }
            sb.append(ans + "\n");
        }
        System.out.println(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}