#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    unordered_map <string, vector<string>> mp;
    unordered_map <string, string> mp2;
    for(int i = 0; i < n; i++){
        string name; cin >> name;
        int size; cin >> size;
        mp[name] = vector<string>(size);
        for(int j = 0; j < size; j++){
            string member; cin >> member;
            mp[name].push_back(member);
            mp2[member] = name;
        }
        sort(mp[name].begin(), mp[name].end());
    }
    while(m--){
        string query; cin >> query;
        int type; cin >> type;
        if (!type){
            for(auto x : mp[query]){
                if(x != "") cout << x << "\n";
            }
        }
        else cout << mp2[query] << "\n";
    }
}
