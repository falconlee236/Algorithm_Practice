import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[26];
        int mx = 0;
        while (true){
            String line = br.readLine();
            if (line == null) break;
            for(int i = 0; i < line.length(); i++) {
                if (line.charAt(i) == ' ') continue;
                int idx = line.charAt(i) - 'a';
                arr[idx]++;
                mx = Math.max(mx, arr[idx]);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 26; i++){
            if (arr[i] == mx) sb.append((char)(i + 'a'));
        }
        System.out.print(sb);
    }
}