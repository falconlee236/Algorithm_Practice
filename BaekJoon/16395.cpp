#include <iostream>
using namespace std;
int main(){
    int n, k, res = 1; cin >> n >> k; n--; k--;
    for(int i = 1; i <= k; i++){ res *= n - i + 1; res /= i; }
    cout << res;
}