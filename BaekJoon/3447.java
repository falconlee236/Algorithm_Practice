import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null) {
            while (line.contains("BUG")) line = line.replace("BUG", "");
            sb.append(line + "\n");
        }
        System.out.print(sb);
    }
}