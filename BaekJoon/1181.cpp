#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size() ? true : false;
}

int main() {
    int t; cin >> t;
    getchar();
    set<string> s;
    while(t--){
        string str; getline(cin, str);
        s.insert(str);
    }
    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), cmp);
    for(string x : v) cout << x << "\n";
	return 0;
}