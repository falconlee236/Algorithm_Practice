package BaekJoon;
import java.io.*;
import java.util.*;
class main{
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            while (a != b) {
                if (a > b) a /= 2;
                else b /= 2;
            }
            sb.append(Integer.toString(a * 10)).append("\n");
        }
        System.out.println(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}