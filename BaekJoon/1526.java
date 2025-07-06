import java.io.*;
class main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = N; i >= 4; i--){
            String num = String.valueOf(i);
            boolean flag = true;
            for(int j = 0; j < num.length(); j++){
                if (num.charAt(j) != '4' && num.charAt(j) != '7') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println(num);
                break;
            }
        }
    }
}