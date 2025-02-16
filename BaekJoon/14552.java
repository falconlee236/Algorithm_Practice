package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    int[] lst;
    private boolean solve(int idx, int head, int body) {
        if (head == 1 && body == 4) return true;
        for(int i = idx; i < 10; i++){
            if (lst[i] == 0) continue;
            if (lst[i] >= 3 && body < 4){
                lst[i] -= 3;
                if (solve(i, head, body + 1)) return true;
                lst[i] += 3;
            }
            if (lst[i] >= 2 && head == 0){
                lst[i] -= 2;
                if (solve(i, head + 1, body)) return true;
                lst[i] += 2;
            }
            if (i < 7 && lst[i + 1] > 0 && lst[i + 2] > 0){
                lst[i] -= 1;
                lst[i + 1] -= 1;
                lst[i + 2] -= 1;
                if (solve(i, head, body + 1)) return true;
                lst[i] += 1;
                lst[i + 1] += 1;
                lst[i + 2] += 1;
            }
            return false;
        }
        return false;
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int[] arr = new int[9];
        for(int i = 0; i < 13; i++) arr[Integer.parseInt(st.nextToken()) - 1]++;
        for(int i = 0; i < 9; i++){
            if (arr[i] == 4) continue;
            lst = arr.clone();
            lst[i]++;
            int cnt = 0;
            for(int x : lst) {
                if (x == 2) cnt++;
            }
            if (cnt == 7) {
                sb.append((i + 1) + " ");
                continue;
            }
            if (solve(0, 0, 0)) sb.append((i + 1) + " ");
        }
        System.out.println((sb.length() == 0 ? -1 : sb));
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}