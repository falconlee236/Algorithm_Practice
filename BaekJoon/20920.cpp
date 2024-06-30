#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++){
        string word; cin >> word;
        if (word.length() < m) continue;
        mp[word]++;
    }
    vector<pair<string, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b){
        if (a.second == b.second && a.first.length() == b.first.length())
            return a.first < b.first;
        if (a.second == b.second)
            return a.first.length() > b.first.length();
        return a.second > b.second;
    });
    for(auto [x, y] : v) cout << x << "\n";
}