import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = 0, b = 0;
        for(int i = 0; i < 9; i++){
            if (br.readLine().equals("Tiger")) a++;
            else b++;
        }
        System.out.println((a > b ? "Tiger" : "Lion"));
    }
}
