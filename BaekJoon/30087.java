import java.io.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            String str = br.readLine(), ans = "";
            if (str.equals("Algorithm")) ans = "204";
            if (str.equals("DataAnalysis")) ans = "207";
            if (str.equals("ArtificialIntelligence")) ans = "302";
            if (str.equals("CyberSecurity")) ans = "B101";
            if (str.equals("Network")) ans = "303";
            if (str.equals("Startup")) ans = "501";
            if (str.equals("TestStrategy")) ans = "105";
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }
}