package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    String s;
    int ans;
    ArrayList<Long> lst;
    private void solve(int idx){
        if (idx == s.length()){
            if (lst.size() > 1 && lst.get(lst.size() - 2) > lst.get(lst.size() - 1)) return;
            ans++;
            return;
        }
        String tmp = "";
        for(int i = idx; i < s.length(); i++){
            tmp += s.charAt(i);
            if (!lst.isEmpty() && lst.get(lst.size() - 1) > Long.parseLong(tmp, 16)) continue;
            lst.add(Long.parseLong(tmp, 16));
            solve(i + 1);
            lst.remove(lst.size() - 1);
        }
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        lst = new ArrayList<>();
        while (T-->0){
            s = br.readLine();
            ans = 0;
            lst.clear();
            solve(0);
            sb.append(ans + "\n");
        }
        System.out.print(sb);
    }
    public static void main(String[] args) throws Exception{
        new main().solution();      
    } 
}