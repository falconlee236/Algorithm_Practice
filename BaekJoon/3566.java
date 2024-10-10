import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = Integer.parseInt(br.readLine());
        int ans = 123456789;
        for(int i = 0; i < n; i++){
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int x, y;
            x = Math.max((input[0] + arr[0] - 1) / arr[0], (input[2] + arr[2] - 1) / arr[2]);
            y = Math.max((input[1] + arr[1] - 1) / arr[1], (input[3] + arr[3] - 1) / arr[3]);
            ans = Math.min(ans, x * y * arr[4]);
            x = Math.max((input[1] + arr[0] - 1) / arr[0], (input[3] + arr[2] - 1) / arr[2]);
            y = Math.max((input[0] + arr[1] - 1) / arr[1], (input[2] + arr[3] - 1) / arr[3]);
            ans = Math.min(ans, x * y * arr[4]);
        }
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}