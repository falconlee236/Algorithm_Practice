#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 987654321, base = 0; cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        for(int j = 0; j < arr[i].length() - 1; j++){
            if (arr[i][j] != arr[i][j + 1]) base++;
        }
    }
    sort(arr, arr + n);
    do {
        int tmp = base;
        for(int i = 0; i < n - 1; i++){
            if (arr[i].back() != arr[i + 1].front()) tmp++;
        }
        ans = min(ans, tmp);
    } while (next_permutation(arr, arr + n));
    cout << ans;
}