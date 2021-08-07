/*11652*/
/*Got it!*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<long long, int> long_pair;
bool cmp(const long_pair& a, const long_pair& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n; cin >> n;
    map<long long, int> m;
    while(n--){
        long long num; cin >> num;
        if(m.find(num) == m.end()) m.insert(make_pair(num, 0));
        m[num]++;
    }
    
    vector<long_pair> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first;
	return 0;
}