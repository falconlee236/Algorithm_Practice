/*1806*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[100000];
    int n, s; scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    int start = 0, end = 0;
    int sum = 0, ans = 10000000;
    while(end <= n){
        if(sum < s) sum += arr[end++];
        else{
            ans = min(ans, end - start);
            sum -= arr[start++];
        }
    }
    printf("%d", (ans == 10000000 ? 0 : ans));
    return 0;
}