import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true){
            int num = Integer.parseInt(br.readLine());
            if (num == 0) break;
            while (num > 9){
                int tmp = 0;
                while(num > 0){
                    tmp += (num % 10);
                    num /= 10;
                }
                num = tmp;
            }
            sb.append(num + "\n");
        }
        System.out.print(sb);
    }    
}
