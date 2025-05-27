import java.util.*;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            String[] arr = br.readLine().split(" ");
            HashSet<String> s = new HashSet<>();
            while (true){
                String line = br.readLine();
                if (line.equals("what does the fox say?")) break;
                s.add(line.split(" ")[2]);
            }
            for (String str : arr) {
                if (!s.contains(str)) sb.append(str + " ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
//https://www.acmicpc.net/problem/9536