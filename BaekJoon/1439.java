import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int cnt = 1;
        for(int i = 0; i < s.length() - 1; i++){
            if (s.charAt(i) != s.charAt(i + 1)) cnt++;
        }
        System.out.println(cnt >> 1);
    }
}