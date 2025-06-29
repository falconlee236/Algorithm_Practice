import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int Q = Integer.parseInt(br.readLine()), idx = 0;
        Stack<Integer> stk = new Stack<>(), tmp = new Stack<>();
        int[] arr = new int[Q + 1];
        while (Q-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            if (type == 1) {
                stk.push(Integer.parseInt(st.nextToken()));
                arr[idx++] = 1;
            }
            else if (type == 2) {
                tmp.push(stk.pop());
                arr[idx++] = 2;
            }
            else if (type == 3) {
                int num = Integer.parseInt(st.nextToken());
                for(int i = 0; i < num; i++){
                    if (arr[--idx] == 2) stk.push(tmp.pop());
                    else stk.pop();
                }
            }
            else if (type == 4) sb.append(stk.size() + "\n");
            else sb.append((stk.isEmpty() ? -1 : stk.peek()) + "\n");
        }
        System.out.print(sb);
    }
}