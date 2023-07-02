#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool flag = true;
    vector<int> a(8);
    for(int i = 0; i < 8; i++){
        cin >> a[i];
        if (a[i] % 25 != 0 || !(a[i] >= 100 && a[i] <= 675)) flag = false;
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    if (a != b) flag = false;
    cout << (flag ? "Yes" : "No" );
}