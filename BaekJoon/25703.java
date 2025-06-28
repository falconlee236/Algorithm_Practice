import java.io.*;
public class test4 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        String str = "*";
        sb.append("int a;\n");
        for(int i = 1; i <= N; i++) sb.append(String.format("int %sptr%s = &%s%s;\n", str.repeat(i), (i <= 1 ? "" : String.valueOf(i)), (i == 1 ? "a" : "ptr"), (i - 1 <= 1 ? "" : String.valueOf(i - 1))));
        System.out.print(sb);
    }
}