/*10814*/
/*cheating*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, string>> v;
    for(int i = 0; i < n; i++){
        int age; cin >> age;
        string str; cin >> str;
        v.push_back(make_pair(age, str));
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << "\n";
    return 0;
}
