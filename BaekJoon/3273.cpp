#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n;
    int arr[n]; for(int& x: arr) cin >> x;
    cin >> x;
    sort(arr, arr + n);
    int start = 0, end = n - 1, cnt = 0;
    while (start < end){
        if (arr[start] + arr[end] < x) start++;
        else if (arr[start] + arr[end] > x) end--;
        else {
            cnt++;
            start++;
        }
    }
    cout << cnt;
}