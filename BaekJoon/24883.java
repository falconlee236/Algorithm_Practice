import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String tmp = br.readLine();
        bw.append((tmp.equals("N") || tmp.equals("n")) ? "Naver D2" : "Naver Whale");
        bw.flush();
    }
}