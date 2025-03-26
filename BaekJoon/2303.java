package BaekJoon;
import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), ans = 1, mx = -1;
        for(int i = 1; i <= N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] arr = new int[5];
            for(int j = 0; j < 5; j++) arr[j] = Integer.parseInt(st.nextToken());
            int tmp = 0;
            for(int a = 0; a < 5; a++){
                for(int b = a + 1; b < 5; b++){
                    for(int c = b + 1; c < 5; c++){
                        int num = (arr[a] + arr[b] + arr[c]) % 10;
                        tmp = Math.max(tmp, num); 
                    }
                }
            }
            if (mx <= tmp) {
                mx = tmp;
                ans = i;
            }
        }
        System.out.println(ans);
    }
}