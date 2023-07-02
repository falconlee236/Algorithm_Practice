#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string arr[n], key[m];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> key[i];
    map<string, int> mp;
    int def = 0, res = 0;
    for(int i = 0; i < m + 1; i++){
        int num; cin >> num;
        if (i == 0) def = num;
        else mp[key[i - 1]] = num;
    }
    for(int i = 0; i < n; i++){
        if (mp.find(arr[i]) == mp.end()) res += def;
        else res += mp[arr[i]];
    }
    cout << res;
}