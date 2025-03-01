package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    String base, ans;
    ArrayList<Integer> lst;
    String[] map = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    private void solve(int idx) {
        if (!ans.isEmpty() || idx == 7) return;
        StringBuilder sb = new StringBuilder();
        for (int x : lst) sb.append(map[x]);
        char[] tmp = sb.toString().toCharArray();
        if (tmp.length > base.length()) return;
        Arrays.sort(tmp);
        if (new String(tmp).equals(base)) {
            StringBuilder sb2 = new StringBuilder();
            for (int x : lst) sb2.append(x);
            char[] tmp2 = sb2.toString().toCharArray();
            Arrays.sort(tmp2);
            ans = new String(tmp2);
            return;
        }
        for(int i = 0; i < 10; i++){
            lst.add(i);
            solve(idx + 1);
            lst.remove(lst.size() - 1);
        }
    }
    private void solution() throws Exception {
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        for(int i = 1; i <= N; i++){
            char[] tmp  = br.readLine().toCharArray();
            lst = new ArrayList<>();
            Arrays.sort(tmp);
            base = new String(tmp);
            ans = "";
            solve(0);
            sb.append("Case #").append(i).append(": ").append(ans + "\n");
        }
        System.out.print(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}
