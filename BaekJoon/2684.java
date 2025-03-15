import java.io.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        String[] lst = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
        for(int i = 0; i < N; i++){
            String str = br.readLine();
            int[] arr = new int[8];
            for(int j = 2; j < str.length(); j++){
                for (int k = 0; k < 8; k++) {
                    if (str.substring(j - 2, j + 1).equals(lst[k])) arr[k]++;
                }
            }
            for (int j : arr) sb.append(j + " ");
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
