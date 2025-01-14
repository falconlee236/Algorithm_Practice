package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int[] root = new int[N + 1];
        for(int i = 1; i <= N; i++) root[i] = i;
        ArrayList<int[]> lst = new ArrayList<>();
        for(int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            lst.add(new int[]{u, v});
        }
        if (M == 0){
            System.out.println(N);
            return;
        }
        Collections.sort(lst, (o1, o2) -> {
            if (o1[0] == o2[0]) return o1[1] - o2[1];
            return o1[0] - o2[0];
        });
        int s = lst.get(0)[0], e = lst.get(0)[1];
        for(int i = 1; i < M; i++){
            int[] arr = lst.get(i);
            if (e < arr[0]){
                for(int j = s; j <= e; j++) root[j] = s;
                s = arr[0];
                e = arr[1];
            } else e = Math.max(e, arr[1]);
        }
        for(int i = s; i <= e; i++) root[i] = s;
        int ans = 0;
        for(int i = 1; i <= N; i++){
            if (root[i] == i) ans++;
        }
        System.out.println(ans);
    }
}