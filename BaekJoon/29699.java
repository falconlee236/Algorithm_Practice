package BaekJoon;
import java.io.*;

class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("WelcomeToSMUPC".charAt((Integer.parseInt(br.readLine()) - 1) % 14));
    }
}