#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio();
    int n, num; cin >> n;
    bool arr[n];
    for(int i = 0; i < n; i++){
        cin >> num;
        if (arr[num]) {
            cout << num;
            break;
        }
        arr[num] = true;
    }
}