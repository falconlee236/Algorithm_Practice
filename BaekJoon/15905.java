import java.io.*;
import java.util.*;

class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        Data[] arr = new Data[n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            arr[i] = new Data(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(arr);
        int ans = 0;
        for(int i = 5; i < arr.length; i++){
            if (arr[i].num == arr[4].num) ans++;
        }
        System.out.println(ans);
    }
    static class Data implements Comparable<Data>{
        int num;
        int cost;
        Data(int num, int cost){
            this.num = num;
            this.cost = cost;
        }

        @Override
        public int compareTo(Data o){
            if (this.num == o.num) return this.cost - o.cost;
            return o.num - this.num;
        }
    }
}