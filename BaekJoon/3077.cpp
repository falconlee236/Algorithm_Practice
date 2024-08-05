#include <iostream>
#include <map>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0; cin >> n;
    map<string, int> mp;
    int arr[n]; string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        mp[str] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> str;
        arr[i] = mp[str];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if (arr[i] < arr[j]) ans++;
        }
    }
    cout << ans << "/" << n * (n - 1) / 2;
}