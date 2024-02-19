#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n == 0){
        cout << 0;
        return 0;
    }
    int arr[n], ans = 0;
    for(int& x: arr){
        cin >> x;
        ans += x;
    }
    sort(arr, arr + n);
    int cnt = round(n * 0.15);
    for(int i = 0; i < cnt; i++){
        ans -= arr[i];
        ans -= arr[n - i - 1];
    }
    cout << round((double)ans / (n - 2 * cnt));
    return 0;
}
