import java.io.*;

class main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        sb.setLength(0);
        String str = br.readLine();
        for(int i = 0; i < str.length(); i++){
            sb.append(i).append('\n');
        }
        System.out.println(sb);
    }
}