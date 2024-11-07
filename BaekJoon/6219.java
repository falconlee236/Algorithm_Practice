package BaekJoon;
import java.io.*;
import java.util.*;

class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int ans = 0;
        boolean[] isPrime = new boolean[b + 1];
        for(int i = 2; i * i <= b; i++){
            if (isPrime[i]) continue;
            for(int j = i * i; j <= b; j+=i) isPrime[j] = true;
        }
        String D = Integer.toString(d);
        for(int i = a; i <= b; i++){
            if (!isPrime[i] && Integer.toString(i).contains(D)) ans++; 
        }
        System.out.println(ans);
    }
}