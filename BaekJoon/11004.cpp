/*11004*/
/*cheating*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(0); cin.sync_with_stdio(false);
    vector<int> v;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    nth_element(v.begin(), v.begin() + (k - 1), v.end());
    cout << v[k - 1];
    return 0;
}