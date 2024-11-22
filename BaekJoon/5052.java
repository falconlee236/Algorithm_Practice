import java.io.*;
import java.util.*;

class main {
    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++){
            int N = Integer.parseInt(br.readLine());
            TrieNode root = new TrieNode();
            ArrayList<String> arr = new ArrayList<>();
            for(int j = 0; j < N; j++){
                arr.add(br.readLine());
                root.insert(arr.get(j), 0);
            }
            boolean flag = false;
            for(String str : arr){
                flag = flag || root.find(str, 0);
            }
            System.out.println((flag ? "NO" : "YES"));
        }
    }

    private class TrieNode {
        private TrieNode[] children;
        private boolean isEnd;

        public TrieNode() {
            children = new TrieNode[10];
            isEnd = false;
        }

        public void insert(String key, int idx){
            if (key.length() == idx) this.isEnd = true;
            else {
                int next = key.charAt(idx) - '0';
                if (children[next] == null) children[next] = new TrieNode();
                children[next].insert(key, idx + 1);
            }
        }

        public boolean find(String key, int idx){
            if (key.length() == idx){
                for(int i = 0; i < 10; i++){
                    if (children[i] != null) return true;
                }
                return false;
            }
            int next = key.charAt(idx) - '0';
            return children[next].find(key, idx + 1);
        }
    }

    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}
