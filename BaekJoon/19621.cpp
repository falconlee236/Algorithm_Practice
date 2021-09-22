/*19621*/
/*Cheating*/
#include <iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int>> v;
int n, ans = -1; 
void solve(int pos, int sum){
    if(pos > n - 1){
        ans = max(ans, sum);
        return;
    }
    solve(pos + 2, sum + v[pos].second);
    solve(pos + 1, sum);
}


int main(){
    cin >> n;
    v = vector<pair<pair<int, int>, int>>(n);
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        v[i] = {{a, b}, c};
    }
    solve(0, 0);
    cout << ans;
}