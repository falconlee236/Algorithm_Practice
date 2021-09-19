/*1764*/
/*Got it!*/
/*04:15*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        mp[str] = 1;
    }
    int ans = 0;
    vector<string> v;
    for(int i = 0; i < m; i++){
        string str; cin >> str;
        if(mp[str]){
            ans++;
            v.push_back(str);
        }
    }
    cout << ans << "\n";
    sort(v.begin(), v.end());
    for(string s : v){
        cout << s << "\n";
    }
    return 0;
}