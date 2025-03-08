import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Integer[][] arr = new Integer[N][2];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken()) * 100 + Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken()) * 100 + Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr, (a, b) -> (a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]));
        int start = 301, end = 1201, idx = 0, max = 0, cnt = 0;
        while (start < end) {
            boolean isFind = false;
            for(int i = idx; i < N; i++){
                if (start < arr[i][0]) break;
                if (max < arr[i][1]){
                    max = arr[i][1];
                    isFind = true;
                    idx = i + 1;
                }
            }
            if (isFind){
                start = max;
                cnt++;
            } else break;
        }
        System.out.println((max < end ? 0 : cnt));
    }    
}