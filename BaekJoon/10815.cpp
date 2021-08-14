/*10815*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int arr[500000] = {};
    int ans[500000] = {};
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a; scanf("%d", &a);
        int start = 0, end = n - 1;
        int flag = 0;
        while(start <= end){
            int mid = (start + end) / 2;
            if(arr[mid] < a) start = mid + 1;
            else if(arr[mid] > a) end = mid - 1;
            else{
                flag = 1;
                break;
            };
        }
        ans[i] = flag;
    }
    for(int i = 0; i < m; i++) printf("%d ", ans[i]);
    return 0;
}