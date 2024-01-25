#include <iostream>
using namespace std;

int arr[100010];
int sum_arr[100010];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum_arr[i] = sum_arr[i - 1] + arr[i];
    }
    int M; cin >> M;
    while(M--){
        int i, j; cin >> i >> j;
        cout << sum_arr[j] - sum_arr[i - 1] << "\n";
    }
}

/*
0 10 30 60 100 150
*/