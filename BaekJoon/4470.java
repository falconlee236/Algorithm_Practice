import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = 1; i <= N; i++){
            System.out.printf("%d. %s\n", i, br.readLine());
        }
    }
}