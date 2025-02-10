package BaekJoon;
import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            int N = Integer.parseInt(br.readLine());
            char[] arr = new char[N * 2];
            for(int i = 0; i < (39 + N) / 40; i++){
                String tmp = br.readLine();
                for(int j = 0; j < tmp.length(); j++) arr[i * 80 + j] = tmp.charAt(j);
            }
            StringBuilder sb2 = new StringBuilder();
            for(int i = 0; i < N * 2; i+=2){
                int num = Integer.parseInt(String.valueOf(new char[]{arr[i], arr[i + 1]}), 16);
                if (num > 127 ){
                    int cnt = num - 128 + 3;
                    while (cnt-->0) sb2.append(arr[i + 2]).append(arr[i + 3]);                    
                    i += 2;
                } else {
                    int cnt = num + 1;
                    for(int j = 0; j < cnt * 2; j++) sb2.append(arr[i + 2 + j]);
                    i += cnt * 2;
                }
            }
            String tmp = sb2.toString();
            sb.append(tmp.length() / 2);
            for(int i = 0; i < tmp.length(); i++){
                if (i % 80 == 0) sb.append("\n");
                sb.append(tmp.charAt(i));
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
// 1
//0100101

//0000000000000000FFFFFF66665A5A5A5A5A71727374758008011011135555555555555501020399777777CC
//0000000000000000FFFFFF66665A5A5A5A5A71727374758008011011135555555555555501020399777777CC