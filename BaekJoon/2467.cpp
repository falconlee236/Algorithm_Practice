/*2467*/
/*Got it!*/
#include <iostream>
#include <cmath>
using namespace std;

int arr[100001];

int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    if(arr[0] > 0) printf("%d %d", arr[0], arr[1]);
    else if(arr[n - 1] < 0) printf("%d %d", arr[n - 2], arr[n - 1]);
    else{
        int left = 0, right = n - 1, a, b;
        int res = 2000000000;
        while(left < right){
            int tmp = arr[left] + arr[right];
            if(abs(res - 0) >= abs(tmp - 0)){
                res = tmp;
                a = arr[left];
                b = arr[right];
            }
            
            if(tmp < 0) left++;
            else right--;
        }
        printf("%d %d", a, b);
    }
}