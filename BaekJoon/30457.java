package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), ans = 0;
        int[] cnt = new int[1001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) cnt[Integer.parseInt(st.nextToken())]++;
        for(int i = 0; i < 2; i++){
            for(int j= 1; j <= 1000; j++){
                if (cnt[j] == 0) continue;
                cnt[j]--;
                ans++;
            }
        }
        System.out.println(ans);
    }
}