import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        ArrayList<Integer> lst = new ArrayList<>();
        int T = Integer.parseInt(br.readLine());
        while (T-->0) {
            while (true){
                int N = Integer.parseInt(br.readLine());
                if (N == 0) {
                    Collections.sort(lst, Collections.reverseOrder());
                int ans = 0;
                    boolean flag = false;
                    for(int i = 1; i <= lst.size(); i++){
                        ans += (int)Math.pow(lst.get(i - 1), i) * 2;
                        if(ans >  5000000) {
                            flag = true;
                            break;
                        }
                    }
                    sb.append((flag ? "Too expensive" : ans) + "\n");
                    lst = new ArrayList<>();
                    break;
                }
                lst.add(N);
            }
        }
        System.out.print(sb);
    }    
}
