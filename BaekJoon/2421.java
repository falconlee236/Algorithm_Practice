import java.io.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] dp = new int[N + 1][N + 1];
        for(int i = 1; i <= N; i++){
            for(int j = 2; j <= N; j++){
                int num = Integer.parseInt(Integer.toString(i) + Integer.toString(j));
                boolean flag = true;
                for(int k = 2; k * k <= num; k++){
                    if (num % k == 0) {
                        flag = false;
                        break;
                    }
                }
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + (flag ? 1 : 0);
            }
        }
        System.out.println(dp[N][N]);
    }
}

/*
 * 
두 저금통에 모두 N원이 모두 모이면 됨, 가장 처음 11은 ㅔㅅ지 않음
1 1
1 2
2 2
쭉쭉 ..
소수가 많이 나오는 횟수 출력
dp[a][b] = 숫자가 ab일때 최적값
dp[a][b] = dp[a - 1][b] + dp[a][b - 1] + (본인이 소수면  + 1)
왜냐하면? 양옆에 1씩 올라오니까
dp[0][0] = 0
본인이 소수인지 확인하는건 그냥 O(sqrt(N))으로 하자

n = 4
1,1 → 2,1 → 3,1 → 4,1 → 4,2 → 4,3 → 4,4

1,1 -> 1,2 -> 1.3 -> 2,3 -> 3,3 -> 4,3 -> 4,4

 */