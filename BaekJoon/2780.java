import java.io.*;
public class test2 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), DIV = 1_234_567;
        int[][] dp = new int[N + 1][10];
        for(int i = 0; i < 10; i++) dp[1][i] = 1;
        for(int i = 2; i <= N; i++){
            dp[i][0] = (dp[i][0] + dp[i - 1][7]) % DIV;
            dp[i][1] = (dp[i][1] + dp[i - 1][4] + dp[i - 1][2]) % DIV;
            dp[i][2] = (dp[i][2] + dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][3]) % DIV;
            dp[i][3] = (dp[i][3] + dp[i - 1][2] + dp[i - 1][6]) % DIV;
            dp[i][4] = (dp[i][4] + dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % DIV;
            dp[i][5] = (dp[i][5] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % DIV;
            dp[i][6] = (dp[i][6] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % DIV;
            dp[i][7] = (dp[i][7] + dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % DIV;
            dp[i][8] = (dp[i][8] + dp[i - 1][7] + dp[i - 1][5] + dp[i - 1][9]) % DIV;
            dp[i][9] = (dp[i][9] + dp[i - 1][8] + dp[i - 1][6]) % DIV;
        }
        StringBuilder sb = new StringBuilder();
        while (N-->0){
            int tmp = Integer.parseInt(br.readLine()), ans = 0;
            for(int i = 0; i < 10; i++) ans = (ans + dp[tmp][i]) % DIV; 
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }
}