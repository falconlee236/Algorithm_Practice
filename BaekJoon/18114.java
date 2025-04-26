package BaekJoon;
import java.util.*;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        HashSet<Integer> s = new HashSet<>();
        boolean flag = false;
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
            s.add(arr[i]);
            if (arr[i] == C) flag = true;
        }
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++){
                if (arr[i] + arr[j] == C) flag = true;
                int tmp = C - (arr[i] + arr[j]);
                if (tmp != arr[i] && tmp != arr[j] && s.contains(tmp)) flag = true;
            }
        }
        System.out.println((flag ? 1 : 0));
    }    
}
