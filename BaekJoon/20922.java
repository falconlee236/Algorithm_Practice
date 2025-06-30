import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken()), ans = 0, tmp = 0;
        int[] arr = new int[N], cnt = new int[100001];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        for(int i = 0, j = -1; i < N; i++){
            tmp++;
            cnt[arr[i]]++;
            if (cnt[arr[i]] > K) {
                ans = Math.max(ans, tmp - 1);
                do {
                    j++;
                    cnt[arr[j]]--;
                    tmp--;
                } while (arr[j] != arr[i] && j < N);
            }
        }
        ans = Math.max(ans, tmp);
        System.out.println(ans);
    }
}
