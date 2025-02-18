import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        char[][] arr = new char[M][N];
        for(int i = 0; i < N; i++){
            String tmp = br.readLine();
            for(int j = 0; j < M; j++){
                char c = tmp.charAt(j);
                if (c == '.') arr[M - j - 1][i] = '.';
                else if (c == 'O') arr[M - j - 1][i] = 'O';
                else if (c == '-') arr[M - j - 1][i] = '|';
                else if (c == '|') arr[M - j - 1][i] = '-';
                else if (c == '/') arr[M - j - 1][i] = '\\';
                else if (c == '\\') arr[M - j - 1][i] = '/';
                else if (c == '^') arr[M - j - 1][i] = '<';
                else if (c == '<') arr[M - j - 1][i] = 'v';
                else if (c == 'v') arr[M - j - 1][i] = '>';
                else if (c == '>') arr[M - j - 1][i] = '^';
            }
        }
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++) sb.append(arr[i][j]);
            sb.append("\n");
        }
        System.out.println(sb);
    }
}

// 3, 5 -> 0, 3
// 3, 0 -> 5, 3
// 6, 2 -> 3, 6