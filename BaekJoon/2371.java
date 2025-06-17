import java.io.*;
import java.util.*;
class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), len = 0;
        ArrayList<Integer>[] lst = new ArrayList[N];
        for(int i = 0; i < N; i++) {
            lst[i] = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (true){
                int num = Integer.parseInt(st.nextToken());
                if (num == -1) break;
                lst[i].add(num);
            }
            len = Math.max(len, lst[i].size());
        }
        HashSet<Integer> s = new HashSet<>();
        for(int i = 0; i < len; i++){
            int size = 0;
            s.clear();
            for(int j = 0; j < N; j++){
                if (lst[j].size() <= i) continue;
                size++;
                s.add(lst[j].get(i));
            }
            if (s.size() == size) {
                System.out.println(i + 1);
                break;
            }
        }
    }
}