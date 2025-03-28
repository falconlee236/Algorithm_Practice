package BaekJoon;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int[] arr = new int[21];
        arr[0] = 1;
        arr[1] = 2;
        for(int i = 2; i <= 20; i++) arr[i] = arr[i - 1] + arr[i - 2];
        while (T-->0){
            int n = Integer.parseInt(br.readLine()), ans = 0;
            for(int i = 20; i >= 0; i--){
                if (n >= arr[i]) {
                    n -= arr[i];
                    if (i > 0) ans += arr[i - 1];
                }
            }
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }    
}