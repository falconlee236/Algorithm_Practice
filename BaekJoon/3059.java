import java.io.*;
class test {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            boolean[] idx = new boolean[26];
            String line = br.readLine();
            int ans = 0;
            for(int i = 0; i < line.length(); i++) idx[line.charAt(i) - 'A'] = true;
            for(int i = 0; i < idx.length; i++) ans += (idx[i] ? 0 : i + 'A');
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }    
}
// https://www.acmicpc.net/problem/3059