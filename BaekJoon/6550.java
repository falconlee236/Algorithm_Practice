import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            String line = br.readLine();
            if (line == null) break;
            String[] arr = line.split(" ");
            int idx = 0;
            for(int i = 0; i < arr[1].length() && idx < arr[0].length(); i++){
                if (arr[0].charAt(idx) == arr[1].charAt(i)) idx++;
            }
            sb.append((idx == arr[0].length() ? "Yes" : "No") + "\n");
        }
        System.out.print(sb);
    }
}
// https://www.acmicpc.net/problem/6550