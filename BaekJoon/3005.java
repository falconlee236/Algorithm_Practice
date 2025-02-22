import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken());
        char[][] arr = new char[R][C];
        for(int i = 0; i < R; i++) arr[i] = br.readLine().toCharArray();
        TreeSet<String> s = new TreeSet<>();
        for(int i = 0; i < R; i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < C; j++) {
                if (arr[i][j] == '#') {
                    if (sb.length() > 1) s.add(sb.toString());
                    sb.setLength(0);
                    continue;
                }
                sb.append(arr[i][j]);
            }
            if (sb.length() > 1) s.add(sb.toString());
        }
        for(int i = 0; i < C; i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < R; j++) {
                if (arr[j][i] == '#') {
                    if (sb.length() > 1) s.add(sb.toString());
                    sb.setLength(0);
                    continue;
                }
                sb.append(arr[j][i]);
            }
            if (sb.length() > 1) s.add(sb.toString());
        }
        System.out.print(s.first());
    }
}