import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long L = Long.parseLong(st.nextToken()), R = Long.parseLong(st.nextToken()), X = 0, Y = 0;
        if ((L - 1) % 4 == 0) X = L - 1;
        else if ((L - 1) % 4 == 1) X = 1;
        else if ((L - 1) % 4 == 2) X = L;
        else X = 0;
        if (R % 4 == 0) Y = R;
        else if (R % 4 == 1) Y = 1;
        else if (R % 4 == 2) Y = R + 1;
        else Y = 0;
        System.out.println(X ^ Y);
    }
}