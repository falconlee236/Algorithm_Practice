package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int[] arr = new int[M];
        String[][] lst = new String[N][2];
        int ans = Integer.MAX_VALUE, idx = 0;
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            lst[i][0] = st.nextToken();
            lst[i][1] = st.nextToken();
            for(int j = 0; j < M; j++) arr[j] += (lst[i][1].charAt(j) != '1' ? 0 : (lst[i][0].equals("L") ? -1 : 1));
        }
        for(int i = 0; i < N; i++){
            int tmp = Integer.MIN_VALUE, sum = 0;
            for(int j = 0; j < M; j++){
                sum += arr[j] - (lst[i][1].charAt(j) != '1' ? 0 : (lst[i][0].equals("L") ? -1 : 1));
                tmp = Math.max(tmp, Math.abs(sum));
            }
            if (tmp < ans){
                ans = tmp;
                idx = i + 1;
            }
        }
        sb.append(idx + "\n").append(ans);
        System.out.print(sb);
    }    
}