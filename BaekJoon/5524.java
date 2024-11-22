package BaekJoon;
import java.io.*;

class main{
    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++) {
            String str = br.readLine();
            System.out.println(str.toLowerCase());
        }
    }

    public static void main(String[] args) throws Exception{
        new main().solution();    
    }
}