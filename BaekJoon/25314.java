import java.io.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        sb.append("tni");
        for(int i = 0; i < N / 4; i++){
            sb.append(" gnol");
        }
        sb.reverse();
        System.out.print(sb);
    } 
}