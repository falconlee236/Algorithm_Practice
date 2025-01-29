package BaekJoon;
import java.io.*;
class main {
    int N, ans = 101;
    String[] arr;
    boolean[] v;
    private void solve(int cnt, String res){
        if (cnt == N){
            ans = Math.min(ans, res.length());
            return;
        }
        for(int i = 0; i < N; i++){
            if (v[i]) continue;
            v[i] = true;
            int idx = 0;
            for(int j = 1; j <= arr[i].length() && j <= res.length(); j++){
                if (res.substring(res.length() - j).equals(arr[i].substring(0, j))){
                    idx = j;
                }
            }
            if (res.length() == 0 || idx > 0) solve(cnt + 1, res + arr[i].substring(idx));
            v[i] = false;
        }
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new String[N];
        v = new boolean[N];
        for(int i = 0; i < N; i++) arr[i] = br.readLine();
        solve(0, "");
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}

/*
문자열 개수는 9개, 문자열 길이는 10 이하
그러면 9!개만큼 경우의 수가 나옴 -> 순열, 10! => 약 4백만 -> 4 * 10^6
그럼 9!은 4 * 10^5
한번 경우의 수에 10 * 10 = 길이가 100개
-> 4 * 10 ^5 * 100 = 4 * 10^7 충분히 가능.

접두사 접미사 문제
VIRUS + RUST + STAND
VIRUSTAND
 */