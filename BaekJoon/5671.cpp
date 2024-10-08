#include <iostream>
#include <cstring>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m){
        int ans = 0;
        for(int i = n; i <= m; i++){
            string s = to_string(i);
            int arr[10]; memset(arr, 0, sizeof(arr));
            bool flag = true;
            for(char c : s) arr[c - '0']++;
            for(int x : arr){
                if (x > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        cout << ans << "\n";
    }
}