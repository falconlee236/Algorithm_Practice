import java.io.*;
import java.util.*;

class main {
    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        while (true){
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            if (N == 0) break;
            int[] arr = new int[10];
            for(int i = 0; i < N; i++){
                int num = Integer.parseInt(st.nextToken());
                arr[num]++;
            }
            int a = 0, b = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < 10; j++){
                    if (arr[j] == 0 || (j == 0 && i < 2)) continue;
                    if (i % 2 == 0) {
                        a *= 10;
                        a += j;
                    }
                    else {
                        b *= 10;
                        b += j;
                    }
                    arr[j]--;
                    break;
                }
            }
            sb.append(Integer.toString(a + b)).append("\n");
        }
        System.out.println(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}
