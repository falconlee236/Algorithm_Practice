import java.io.*;
import java.util.*;
class main {
    long[] arr;
    private int lower_bound(long num){
        int s = 0, e = arr.length;
        while (s < e){
            int mid = (s + e) / 2;
            if (arr[mid] < num) s = mid + 1;
            else e = mid;
        }
        return e;
    }
    private int upper_bound(long num){
        int s = 0, e = arr.length;
        while (s < e){
            int mid = (s + e) / 2;
            if (arr[mid] <= num) s = mid + 1;
            else e = mid;
        }
        return e;
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        arr = new long[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Long.parseLong(st.nextToken());
        Arrays.sort(arr);
        while (M-->0){
            st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            if (type == 3){
                long i = Long.parseLong(st.nextToken());
                long j = Long.parseLong(st.nextToken());
                sb.append(upper_bound(j) - lower_bound(i) + "\n");
                continue;
            }
            long k = Long.parseLong(st.nextToken());
            if (type == 2) sb.append((N - upper_bound(k)) + "\n");
            else sb.append((N - lower_bound(k)) + "\n");
        }
        System.out.print(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}