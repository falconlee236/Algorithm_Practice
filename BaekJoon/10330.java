import java.io.*;
import java.util.*;
public class test {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), one = 0;
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            one += arr[i];
        }
        st = new StringTokenizer(br.readLine());
        StringBuilder sb1 = new StringBuilder(), sb2 = new StringBuilder();
        for(int i = 0; i < M; i++) {
            int num = Integer.parseInt(st.nextToken());
            while (num-->0) {
                sb1.append((i % 2 == 0 ? '0' : '1'));
                sb2.append((i % 2 == 0 ? '1' : '0'));   
            }
        }
        String s1 = sb1.toString(), s2 = sb2.toString();
        int idx1 = 0, idx2 = 0, ans1 = 0, ans2 = 0, one_cnt1 = 0, one_cnt2 = 0, ans = Integer.MAX_VALUE;
        for(int i = 0; i < N; i++){
            if (s1.charAt(i) == '1'){
                while (idx1 < N){
                    if (arr[idx1] == 1) {
                        ans1 += (int)Math.abs(i - idx1);
                        idx1++;
                        break;
                    }
                    idx1++;
                }
                one_cnt1++;
            }
            if (s2.charAt(i) == '1'){
                while (idx2 < N){
                    if (arr[idx2] == 1) {
                        ans2 += (int)Math.abs(i - idx2);
                        idx2++;
                        break;
                    }
                    idx2++;
                }
                one_cnt2++;
            }
        }
        if (one_cnt1 == one) ans = Math.min(ans1, ans);
        if (one_cnt2 == one) ans = Math.min(ans2, ans);
        System.out.println(ans);
    }
}

/*
1의 거리 계산하기, 이게 골드 5라고? 골드 4~3은 될거 같은데
1110000

0000111
1111000

100011
011100
 */