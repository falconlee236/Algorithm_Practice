package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        for(int t = 0; t < 3; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String x = st.nextToken(), y = st.nextToken();
            boolean[] x_list = new boolean[10], y_list = new boolean[10];
            for(int i = 0; i < x.length(); i++) x_list[x.charAt(i) - '0'] = true;
            for(int i = 0; i < y.length(); i++) y_list[y.charAt(i) - '0'] = true;
            boolean flag = true;
            for(int i = 0; i < 10; i++){
                if (x_list[i] != y_list[i]) flag = false;
            }
            if (flag) {
                sb.append("friends\n");
                continue;
            }
            flag = false;
            for(int i = 0; i < x.length() - 1; i++){
                char[] x_char = x.toCharArray();
                boolean[] tmp = new boolean[10];
                boolean tmp_flag = true;
                if (x_char[i + 1] != '0' && x_char[i] != '9') {
                    x_char[i] += 1;
                    x_char[i + 1] -= 1;
                    for(int j = 0; j < x.length(); j++) tmp[x_char[j] - '0'] = true;
                    for(int j = 0; j < 10; j++){
                        if (tmp[j] != y_list[j]) tmp_flag = false;
                    }
                    flag = flag || tmp_flag;
                }
                x_char = x.toCharArray();
                if (i == 0 && x_char[i] == '1') continue;
                tmp = new boolean[10];
                tmp_flag = true;
                if (x_char[i] != '0' && x_char[i + 1] != '9') {
                    x_char[i] -= 1;
                    x_char[i + 1] += 1;
                    for(int j = 0; j < x.length(); j++) tmp[x_char[j] - '0'] = true;
                    for(int j = 0; j < 10; j++){
                        if (tmp[j] != y_list[j]) tmp_flag = false;
                    }
                    flag = flag || tmp_flag;
                }
            }
            if (flag) {
                sb.append("almost friends\n");
                continue;
            }
            flag = false;
            for(int i = 0; i < y.length() - 1; i++){
                char[] y_char = y.toCharArray();
                boolean[] tmp = new boolean[10];
                boolean tmp_flag = true;
                if (y_char[i + 1] != '0' && y_char[i] != '9') {
                    y_char[i] += 1;
                    y_char[i + 1] -= 1;
                    for(int j = 0; j < y.length(); j++) tmp[y_char[j] - '0'] = true;
                    for(int j = 0; j < 10; j++){
                        if (tmp[j] != x_list[j]) tmp_flag = false;
                    }
                    flag = flag || tmp_flag;
                }
                y_char = y.toCharArray();
                if (i == 0 && y_char[i] == '1') continue;
                tmp = new boolean[10];
                tmp_flag = true;
                if (y_char[i] != '0' && y_char[i + 1] != '9') {
                    y_char[i] -= 1;
                    y_char[i + 1] += 1;
                    for(int j = 0; j < y.length(); j++) tmp[y_char[j] - '0'] = true;
                    for(int j = 0; j < 10; j++){
                        if (tmp[j] != x_list[j]) tmp_flag = false;
                    }
                    flag = flag || tmp_flag;
                }
            }
            if (flag) {
                sb.append("almost friends\n");
                continue;
            }
            sb.append("nothing\n");
        }
        System.out.print(sb);
    }
}