#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int n; cin >> n;
        long long arr[n]; for(auto &x : arr) cin >> x;
        int idx = n - 1;
        while (idx >= 2){
            for(int i = 0; i <= idx / 2; i++) arr[i] += arr[idx - i];
            idx /= 2;
        }
        cout << "Case #" << t << ": " << (arr[0] > arr[1] ? "Alice" : "Bob") << "\n";
    }
}