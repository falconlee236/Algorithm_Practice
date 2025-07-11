#include <iostream>
#include <map>
#define INF 0xFFFFFFF
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = INF; cin >> n;
    string str; cin >> str;
    map<char, char> mp = {{'R', 'G'}, {'G', 'B'}, {'B', 'R'}};
    auto change = [&mp](string &s, int a, int b, int c){
        s[a] = mp[s[a]];
        s[b] = mp[s[b]];
        s[c] = mp[s[c]];
    };
    for(int t = 0; t < 3; t++){
        int tmp = t;
        string tmp_str = str;
        for(int i = 1; i < n - 2; i++){
            while (tmp_str[i] != tmp_str[0]) {
                change(tmp_str, i, i + 1, i + 2);
                tmp++;
            }
        }
        if (tmp_str[0] == tmp_str[n - 2] && tmp_str[0] == tmp_str[n - 1]) ans = min(ans, tmp);
        change(str, 0, 1, 2);
    }
    cout << (ans == INF ? -1 : ans);
}