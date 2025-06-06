import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String a = br.readLine(), b = br.readLine();
        for(int i = 0; i < a.length(); i++){
            int diff = b.charAt(i) - a.charAt(i);
            sb.append(diff <= 0 ? (char)(diff + 26 + 'A' - 1) : (char)(diff + 'A' - 1));
        }
        String ans = sb.toString();
        int total = ans.length(), mn = ans.length();
        ArrayList<Integer> lst = new ArrayList<>();
        for(int i = 1; i * i <= total; i++){
            if (total % i == 0) {
                lst.add(i);
                lst.add(total / i);
            }
        }
        Collections.sort(lst, Collections.reverseOrder());
        for(int x : lst){
            boolean flag = true;
            for(int i = 0; i < total; i+=x){
                if (!ans.substring(i, i + x).equals(ans.substring(0, x))) flag = false;
            }
            if (flag) mn = Math.min(mn, x);
        }
        System.out.println(ans.substring(0, mn));
    }
}

/*
BIGDATASECURITY
UNVYMMFHZONWXOK

(B + key) - 26 = results
key = results + 26 - B
즉 results - 원문 이 음수이면 26을 더하면 된다.

 */