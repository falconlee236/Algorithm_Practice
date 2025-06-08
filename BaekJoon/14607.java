//https://www.acmicpc.net/problem/14607
import java.io.*;
import java.util.*;
class main {
    HashMap<Long, Long> mp = new HashMap<>();
    private long solve(long n){
        if (n == 1) return 0;
        if (mp.containsKey(n)) return mp.get(n);
        long left = n / 2, right = (n % 2 == 1 ? (n / 2 + 1) : n / 2);
        mp.put(n, left * right + solve(left) + solve(right));
        return mp.get(n);
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        System.out.println(solve(N));
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}


/*
3 -> 3
4 -> 2 * 2 = 4 + (1 * 1) * (1 * 1) = 6
5 -> 3 * 2 = 6
3 + 1
 */