#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;
ll max_value = LLONG_MIN, min_value = LLONG_MAX;
int n, cnt;
vector<ll> arr, op;

void solve(int idx, ll tmp){
    if(idx == cnt){
        max_value = max(max_value, tmp);
        min_value = min(min_value, tmp);
        return ;
    }
    for(int i = 0; i < 4; i++){
        if (op[i] == 0) continue;
        op[i]--;
        switch (i){
            case 0:
                solve(idx + 1, tmp + arr[idx + 1]);
                break;
            case 1:
                solve(idx + 1, tmp - arr[idx + 1]);
                break;
            case 2:
                solve(idx + 1, tmp * arr[idx + 1]);
                break;
            case 3:
                solve(idx + 1, tmp / arr[idx + 1]);
                break;
        }
        op[i]++;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    arr = vector<ll> (n);
    op = vector<ll> (4);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++){
        cin >> op[i];
        cnt += op[i];
    }
    solve(0, arr[0]);
    cout << max_value << "\n" << min_value;
}