import java.io.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            String[] arr = br.readLine().split(" ");
            for (String s : arr) {
                StringBuilder ss = new StringBuilder(s);
                ss.reverse();
                sb.append(ss.toString() + " ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}