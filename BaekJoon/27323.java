import java.io.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), M = Integer.parseInt(br.readLine());
        System.out.println(N * M);
    }    
}
