import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        long ans = 0;
        Queue<Integer>[] arr = new Queue[21];
        for(int i = 2; i < 21; i++) arr[i] = new LinkedList<>();
        for(int i = 0; i < N; i++){
            int len = br.readLine().length();
            while (!arr[len].isEmpty() && arr[len].peek() < i - K) arr[len].poll();
            ans += arr[len].size();
            arr[len].add(i);
        }
        System.out.println(ans);
    }
}

/*
 queue + sliding window
 등수의 차이가 K보다 작거나 같으면서 이름의 길이가 같은 친구이다.
*/