package BaekJoon;
import java.io.*;
class main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long ans = 2;
        for(int i = 2; i < N; i++){
            ans *= 3;
            ans %= 1_000_000_009;
        }
        System.out.println((N == 1 ? 0 : ans));
    }
}

/*
 * 
 * 나머지 연산 쓰는 문제임 + 2차원배열
 * 1 + 2, 
 * dp(2) = 12, 21 = 2
 * dp(3) = 120, 102, 210, 201, 111, 222 = 6
 * 맨앞에 2가지, N - 1자리 숫자 중에서 0, 1, 2를 사용해서 N - 2 자릿수를 만드는 경우의수
 * 3^(N - 2) * 2. 나머지 1자리는 그냥 맞추면 된다
 */