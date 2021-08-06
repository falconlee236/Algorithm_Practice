/*11651*/
/*cheating*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << "\n";
    return 0;
}
