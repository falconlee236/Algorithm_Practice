import java.io.*;
import java.util.*;

class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++){
            int num = Integer.parseInt(br.readLine());
            char ans = '0';
            for(int j = 2; j <= 64; j++){
                ArrayList<Integer> arr = new ArrayList<>();
                int tmp = num;
                while (tmp > 0) {
                    arr.add(tmp % j);
                    tmp /= j;
                }
                int start = 0, end = arr.size() - 1;
                boolean flag = true;
                while (start <= end){
                    if (!arr.get(start).equals(arr.get(end))) {
                        flag = false;
                        break;
                    }
                    start++;
                    end--;
                }
                if (flag) ans = '1';
            }
            sb.append(ans).append('\n');
        }
        System.out.println(sb);
    }
}
