/*2805*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m; scanf("%d %d", &n, &m);
    int arr[1000001];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int height = 0;
    int start = 0, end = arr[n - 1];
    while(start <= end){
        long long res = 0;
        int mid = (start + end) / 2;
        for(int i = 0; i < n; i++) res += (arr[i] - mid > 0 ? arr[i] - mid : 0);
        if(res >= m){
            start = mid + 1;
            height = mid;
        }
        else end = mid - 1;
    }
    printf("%d", height);
}