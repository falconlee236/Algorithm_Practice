import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        int arr[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(arr);
        int s = 0, e = N - 1, ans = 0;
        while (s < e){
            if (arr[s] + arr[e] <= K) {
                ans++;
                s++;
                e--;
            } else {
                e--;
            }
        }
        System.out.println(ans);
    }    
}



/*
 * 
 * 
 * 
5 20 -> 2
8 16 11 2 4

2 4 8 11 16

6 10 -> 2
9 5 6 7 4 3

3 4 5 6 7 9

4 100 -> 0
100 99 98 97
 */