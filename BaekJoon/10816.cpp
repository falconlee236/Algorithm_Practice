#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        mp[num]++;
    }
    int t; cin >> t;
    while (t--){
        int num; cin >> num;
        cout << mp[num] << " ";
    }
}