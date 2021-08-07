/*10825*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, vector<int>> str_pair;

bool cmp(const str_pair& a, const str_pair& b){
    if(a.second[0] == b.second[0] && a.second[1] == b.second[1] && a.second[2] == b.second[2]) return a.first < b.first;
    if(a.second[0] == b.second[0] && a.second[1] == b.second[1]) 
        return a.second[2] > b.second[2];
    if(a.second[0] == b.second[0]) return a.second[1] < b.second[1];
    return a.second[0] > b.second[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<str_pair> v;
    for(int i = 0; i < n; i++){
        vector<int> u;
        string str; cin >> str;
        cin.clear();
        int a, b, c; cin >> a >> b >> c;
        u.push_back(a); u.push_back(b); u.push_back(c);
        v.push_back(make_pair(str, u));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) cout << v[i].first << "\n";
    return 0;
}
