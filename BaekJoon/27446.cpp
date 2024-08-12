#include <iostream>
using namespace std;
int arr[101];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, num, ans = 0, start = 0; cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> num;
        arr[num]++;
    }
    for(int i = 1; i <= n; i++){
        if (arr[i]) continue;
        if (!start) ans += 7;
        else ans += min(7, (i - start) * 2);
        start = i;
    }
    cout << ans;
}

/*
15 6
4 5 6 11 12 13
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
0 0 0 1 1 1 0 0 0 0  1  1  1  0  0
5 + 2 * 3 + 5 + 2 * 4 + 5 + 2 * 2


10 8
5 7 9 10 3 4 4 3

1 2 3 4 5 6 7 8 9 10
0 0 2 2 1 0 1 0 1 1


0 1 0
-> 5 + 2 + 5 + 2 = 14
-> 5 + 2 * 3 = 11

0 1 1 0
-> 14 vs
-> 5 + 2 * 4 = 13

0 1 1 1 0
-> 14 vs
-> 5 + 2 * 5 = 15

0 1 0 0
-> 5 + 2 + 5 + 2 * 2 = 16
-> 5 + 2 * 4 = 13
*/