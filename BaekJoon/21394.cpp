#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int arr[9], len = 0;
        for(int& x : arr){
            cin >> x; len += x;
        }
        arr[8] += arr[5];
        arr[5] = 0;
        int left = 0, right = len - 1, ans[len], cnt = 0;
        for(int i = 8; i >= 0; i--){
            while (arr[i]){
                if (cnt % 2 == 0) ans[left++] = i + 1;
                else ans[right--] = i + 1;
                arr[i]--;
                cnt++;
            }
        }
        for(int x: ans) cout << x << " ";
        cout << "\n";
    }
}