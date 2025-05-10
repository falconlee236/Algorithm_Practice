import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] arr = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        long div = Long.parseLong(br.readLine()), ans = 0;
        for(long x : arr) ans += (x + div - 1) / div;
        System.out.println(ans * div);
    }
}