import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int arr[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        sb.append(arr[0] + " ");
        int sum = arr[0];
        for(int i = 1; i < N; i++){
            int ans = arr[i] * (i + 1) - sum;
            sb.append(ans + " ");
            sum += ans;
        }
        System.out.println(sb);
    }
}