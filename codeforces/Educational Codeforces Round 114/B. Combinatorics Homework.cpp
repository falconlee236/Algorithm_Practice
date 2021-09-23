#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int arr[3];
        for(int i = 0; i < 3; i++) cin >> arr[i];
        int m; cin >> m;
        sort(arr, arr + 3);
        cout << ((arr[2] - (arr[0] + arr[1] + 1) <= m && m <= (arr[0] + arr[1] + arr[2] - 3)) ? "YES" : "NO") << "\n";;
    }
}