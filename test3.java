import java.io.*;
import java.util.*;
public class test3 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int R = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken());
            int[][] arr = new int[R + 1][C + 1];
            for(int i = 1; i <= R; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 1; j <= C; j++) arr[i][j] = Integer.parseInt(st.nextToken());
            }
            for(int i = 1; i <= R; i++){
                for(int j = 1; j <= C; j++){
                    int value = arr[i][j], predict = 0, filter = 0;
                    predict = arr[i][j] - arr[i][j - 1];
                    if (Math.abs(predict) < Math.abs(value)) {
                        filter = 1;
                        value = predict;
                    }
                    predict = arr[i][j] - arr[i - 1][j];
                    if (Math.abs(predict) < Math.abs(value)) {
                        filter = 2;
                        value = predict;
                    }
                    predict = arr[i][j] - (arr[i - 1][j] + arr[i][j - 1]) / 2;
                    if (Math.abs(predict) < Math.abs(value)) {
                        filter = 3;
                        value = predict;
                    }
                    predict = arr[i][j] - (arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
                    if (Math.abs(predict) < Math.abs(value)) {
                        filter = 4;
                        value = predict;
                    }
                    System.out.print(filter + " " + value + " ");
                }
                System.out.println();
            }
        }
    }
}

// https://www.acmicpc.net/problem/28345