/*9613*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int t; scanf("%d", &t);
    int arr[100];
    while(t--){
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        long long res = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++) res += gcd(max(arr[i], arr[j]), min(arr[i], arr[j]));
        }
        printf("%lld\n", res);
    }
}