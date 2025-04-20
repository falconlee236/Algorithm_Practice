import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[51];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            int num = Integer.parseInt(st.nextToken());
            arr[num]++;
        }
        int mul = 1, ans = 0;
        for(int i = 1; i <= 50; i++){
            ans += (mul * arr[i]);
            mul *= arr[i];
        }
        System.out.println(ans);
    }
}
