// https://www.acmicpc.net/problem/2107
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<int[]> lst = new ArrayList<>();
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] arr = new int[2];
            arr[0] = Integer.parseInt(st.nextToken());
            arr[1] = Integer.parseInt(st.nextToken());
            lst.add(arr);
        }
        Collections.sort(lst, (int[] x, int[] y) -> x[0] - y[0]);
        int mx = 0;
        for(int i = 0; i < lst.size(); i++){
            int tmp = 0, e = lst.get(i)[1];
            for(int j = i + 1; j < lst.size(); j++){
                if (lst.get(j)[1] < e) tmp++;
            }
            mx = Math.max(mx, tmp);
        }
        System.out.println(mx);
    }
}
