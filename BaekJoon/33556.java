import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String a = br.readLine(), b = br.readLine();
        sb.append((a.equals("null") ? "NullPointerException" : (b.equals("null") ? false : a.equals(b))) + "\n");
        sb.append((a.equals("null") ? "NullPointerException" : (b.equals("null") ? false : a.equalsIgnoreCase(b))) + "\n");
        System.out.print(sb);
    }
}