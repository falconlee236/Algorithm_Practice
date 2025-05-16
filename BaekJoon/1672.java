import java.io.*;
import java.util.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String str = br.readLine();
        Map<Character, Integer> mp = new HashMap<>();
        mp.put('A', 0);
        mp.put('G', 1);
        mp.put('C', 2);
        mp.put('T', 3);
        Stack<Character> stk = new Stack<>();
        for(int i = 0; i < N; i++) stk.push(str.charAt(i)); 
        char[][] arr = {
            {'A', 'C', 'A', 'G'},
            {'C', 'G', 'T', 'A'},
            {'A', 'T', 'C', 'G'},
            {'G', 'A', 'G', 'T'}
        };
        while(stk.size() > 1){
            int first = mp.get(stk.pop()), second = mp.get(stk.pop());
            stk.push(arr[first][second]);
        }
        System.out.println(stk.peek());
    }
}