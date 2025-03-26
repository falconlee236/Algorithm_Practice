import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long DIV = 1_000_000_000;
        long[][][] dp = new long[N][10][1024];
        for(int i = 1; i < 10; i++) dp[0][i][(1 << i)] = 1;
        for(int i = 1; i < N; i++){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 1024; k++){
                    int state = k | (1 << j);
                    if (j > 0) dp[i][j][state] += dp[i - 1][j - 1][k]; 
                    if (j < 9) dp[i][j][state] += dp[i - 1][j + 1][k];
                    dp[i][j][state] %= DIV;
                }
            }
        }
        long ans = 0;
        for(int i = 0; i < 10; i++) {
            ans += dp[N - 1][i][1023];
            ans %= DIV;
        }
        System.out.println(ans);
    }
}


/*
 * 
 * 쉬운 계단수 
 * dp[a][b] = a번째 자리수에서 b로 끝나는 수의 개수
 * dp[a][b] = dp[a - 1][b - 1] + dp[a - 1][b + 1];  왜냐하면 차이가 1이 나야하기 때문
 * 0은 1만, 9는 8만 인거 주의
 * 
 * 근데 계단수
 * -> 쉬운 계단수에 0~9까지 모두 들어가 있는 경우의 수를 따로 뽑아야함 -> 비트 필드 사용
 * 2^10  = 1024이고, 1023이 11111111 이므로 모두 있는 값
 * 즉 답은 dp[n][b][1023]을 모든 b에 대해서 더해주면 되는구나
 */