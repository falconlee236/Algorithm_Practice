import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            int num = Integer.parseInt(br.readLine());
            sb.append((num / 25) + " ");
            num %= 25;
            sb.append((num / 10) + " ");
            num %= 10;
            sb.append((num / 5) + " ");
            num %= 5;
            sb.append((num / 1) + " ").append("\n");
        }
        System.out.print(sb);
    }
}
