package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        HashMap<Integer, String> mp = new HashMap<>();
        int N = Integer.parseInt(br.readLine());
        String s = br.readLine(), tmp = new String(s);
        mp.put(0, s);
        for(int i = 1;; i++){
            for(int j = 0; j < tmp.length(); j+=2) sb.append(tmp.charAt(j));
            for(int j = tmp.length() - 1 - (tmp.length() % 2 == 0 ? 0 : 1); j >= 0; j-=2) sb.append(tmp.charAt(j));
            if (s.equals(sb.toString())) break;
            tmp = sb.toString();
            mp.put(i, tmp);
            sb.setLength(0);
        }
        System.out.println(mp.get(N % mp.size()));
    }    
}

/*
 * acefdb
 * aedbfc
 * 
 * 홀수번째 문자열을 싹 모은다음 reverse하고 뒤에 붙이기
 * 혹시 회문? -> ㅋㅋㅋ 정답
 * abcdef
 * afbecd
 * adfcbe
 * aedbfc
 * acefdb
 * abcdef
 * 
 * 5번 깜빡이면 원래 글자로 돌아옴 why?
 * 
 * srama
 * saamr
 * sarma
 * srama
 * saamr
 * 
 * 그러면 반복문을 돌려서 원래 자리로 돌아올때 까지 돌리고 나눗셈 해서 그거 뽑으면 끝
 */