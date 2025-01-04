import java.io.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int ans = 0;
        for(int i = 0; i < N; i++){
            String s = br.readLine();
            boolean flag = true;
            for(int j = 0; j < s.length() / 2; j++){
                if (s.charAt(j) != s.charAt(s.length() - j - 1)){
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        System.out.println(ans * (ans - 1));
    }
}