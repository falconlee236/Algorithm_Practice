/*2003*/
/*Cheating*/
#include <iostream>
using namespace std;

int main(){
    int n, m, ans = 0;
    int arr[10000];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)  scanf("%d", &arr[i]);
    
    int start = 0, end = 0;
    int sum = 0;
    while(end <= n){
        if(sum < m) sum += arr[end++];
        else{
            if(sum == m) ans++;
            sum -= arr[start++];
        }
    }
    printf("%d", ans);
    return 0;
}