#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    pair<int, int> subway[1000010];
    int arr[n]; for(int &x : arr) cin >> x;
    if (n == 1) subway[arr[0]] = make_pair(arr[0], arr[0]);
    else{
        for(int i = 0; i < n; i++){
            if (i == 0) subway[arr[i]] = make_pair(arr[n - 1], arr[1]);
            else if (i == n - 1) subway[arr[i]] = make_pair(arr[i - 1], arr[0]);
            else subway[arr[i]] = make_pair(arr[i - 1], arr[i + 1]);
        }
    }
    while (m--){
        string str; cin >> str;
        int i, j;
        if (str == "BN"){
            cin >> i >> j;
            int next = subway[i].second;
            subway[i].second = j;
            cout << next << "\n";
            int prev = subway[next].first;
            subway[next].first = j;
            subway[j] = make_pair(prev, next);    
        } else if (str == "BP"){
            cin >> i >> j;
            int prev = subway[i].first;
            subway[i].first = j;
            cout << prev << "\n";
            int next = subway[prev].second;
            subway[prev].second = j;
            subway[j] = make_pair(prev, next);
        } else if (str == "CN"){
            cin >> i;
            int target = subway[i].second;
            int prev = subway[target].first, next = subway[target].second;
            subway[prev].second = next;
            subway[next].first = prev;
            cout << target << "\n";
        } else if (str == "CP"){
            cin >> i;
            int target = subway[i].first;
            int prev = subway[target].first, next = subway[target].second;
            subway[prev].second = next;
            subway[next].first = prev;
            cout << target << "\n";
        }
    }
}