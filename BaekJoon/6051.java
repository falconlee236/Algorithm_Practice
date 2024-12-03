import java.io.*;
import java.util.*;

class Main{
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        Point[] arr = new Point[N + 1];
        arr[0] = new Point("-1", 0);
        for(int i = 1, j = 0; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            String query = st.nextToken();
            if (query.equals("a")){
                arr[i] = new Point(st.nextToken(), j);
                j = i;
            } else if (query.equals("s")) {
                arr[i] = new Point(arr[j].value, j);
                j = arr[j].prev;
            } else {
                arr[i] = new Point(arr[j].value, j);
                j = arr[Integer.parseInt(st.nextToken())].prev;
            }
            sb.append(arr[j].value).append("\n");
        }
        System.out.println(sb);
    }
    private class Point{
        String value;
        int prev;
        Point(String x, int y){
            value = x;
            prev = y;
        }
    }
    public static void main(String[] args) throws Exception{
        new Main().solution();
    }
}
