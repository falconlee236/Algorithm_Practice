import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int size = 32769;
        int[] dp = new int[size];
        for(int i = 1; i * i < size; i++){
            dp[i * i]++;
            for(int j = i; j * j < size; j++){
                if (i * i + j * j < size) dp[i * i + j * j]++;
                for(int k = j; k * k < size; k++){
                    if (i * i + j * j + k * k < size) dp[i * i + j * j + k * k]++;
                    for(int l = k; l * l < size; l++){
                        if (i * i + j * j + k * k + l * l < size) dp[i * i + j * j + k * k + l * l]++;
                    }
                }
            }
        }
        while (true) {
            int N = Integer.parseInt(br.readLine());
            if (N == 0) break;
            sb.append(dp[N] + "\n");
        }
        System.out.print(sb);
    }
}