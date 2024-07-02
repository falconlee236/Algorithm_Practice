#include <iostream>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, res = 0; cin >> n >> k;
    char arr[n]; for(char& x:arr) cin >> x;
    for(int i = 0; i < n; i++){
        for(int j = i - k; j <= i + k && arr[i] == 'P'; j++){
            if (j < 0 || j >= n || arr[j] != 'H') continue;
            arr[j] = '0';
            res++;
            break;
        }
    }
    cout << res;
}