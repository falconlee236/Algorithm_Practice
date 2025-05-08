import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[3];
        arr[0] = Integer.parseInt(st.nextToken());
        arr[1] = Integer.parseInt(st.nextToken());
        arr[2] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int a = arr[1] - arr[0], b = arr[2] - arr[1];
        if (a == b) System.out.println(arr[2] + b);
        else if (a * 2 == b) System.out.println(arr[2] - a);
        else System.out.println(arr[0] + b);
    }
}