import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String N = br.readLine();
        boolean flag = false;
        for(int i = 1; i < N.length(); i++){
            int a = 1, b = 1;
            for(int j = 0; j < i; j++) a *= (N.charAt(j) - '0');
            for(int j = i; j < N.length(); j++) b *= (N.charAt(j) - '0');
            if (a == b) flag = true;
        }
        System.out.println((flag ? "YES" : "NO"));
    }
}
