package BaekJoon;
import java.io.*;
import java.math.BigDecimal;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        double A = Double.parseDouble(st.nextToken());
        double B = Double.parseDouble(st.nextToken());
        double M = (B - A) / 400;
        BigDecimal bg = new BigDecimal(1 / (1 + Math.pow(10, M)));
        System.out.println(bg.toString());
    }
}