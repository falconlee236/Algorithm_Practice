#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--){
        int arr[10]; for(int &x : arr) cin >> x;
        sort(arr, arr + 10);
        cout << arr[7] << "\n";
    }
}