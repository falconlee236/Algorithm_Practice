#include <iostream>
using namespace std;
struct TrieNode{
    TrieNode* children[10];
    bool isEnd;
    TrieNode() : children(), isEnd(false) {}
    void insert(string &key, int idx){
        if (idx == key.length()) isEnd = true;
        else {
            int next = key[idx] - '0';
            if (children[next] == nullptr) children[next] = new TrieNode;
            children[next]->insert(key, idx + 1);
        }
    }
    bool find(string &key, int idx){
        if (idx == key.length()){
            for(int i = 0; i < 10; i++){
                if (children[i] != nullptr) return true;
            }
            return false;
        } 
        int next = key[idx] - '0';
        return children[next]->find(key, idx + 1);
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, n; cin >> T;
    while (T--){
        cin >> n;
        TrieNode root;
        string arr[n]; for(string &s : arr){
            cin >> s;
            root.insert(s, 0);
        }
        bool flag = false;
        for(string s : arr) flag = flag || root.find(s, 0);
        cout << (flag ? "NO" : "YES") << "\n";
    }
}