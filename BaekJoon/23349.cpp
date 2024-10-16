#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, mx = 0; cin >> n;
    set<string> s;
    map<string, int[50010]> place;
    for(int i = 0; i < n; i++){
        string a, b; int c, d; cin >> a >> b >> c >> d;
        if (s.find(a) != s.end()) continue;
        s.insert(a);
        for(int i = c; i < d; i++){
            place[b][i]++;
            mx = max(mx, place[b][i]);
        }
    }
    vector<pair<string, pair<int, int>>> v;
    for(auto [x, y]: place){
        int start = -1;
        for(int i = 0; i < 50010; i++) {
            if (start == -1 && y[i] == mx) start = i;
            if (start != -1 && y[i] != mx) {
                v.push_back({x, {start, i}});
                start = -1;
            }
        }
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if (a.first == b.first && a.second.first == b.second.first) return a.second.second < b.second.second;
        if (a.first == b.first) return a.second.first < b.second.first;
        return a.first < b.first;
    });
    cout << v.front().first << " " << v.front().second.first << " " << v.front().second.second;
}