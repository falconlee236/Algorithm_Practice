#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--){
        int k; cin >> k;
        int arr[k]; for(auto &x : arr) cin >> x;
        for(int i = 0; i < k - 1; i++){
            if (arr[i] < arr[i + 1]){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}