/*6588*/
/*Got it!*/
#include <iostream>
#include <cmath>
#define MAX 1000001
using namespace std;

int main(){
    int arr[MAX] = {1, 1, };
    for(int i = 2; i < sqrt(MAX); i++){
        if(arr[i] == 1) continue;
        for(int j = i + i; j < MAX; j+= i) arr[j] = 1;
    }
    while(1){
        int n; scanf("%d", &n);
        if(n == 0) break;
        int b = n;
        int a;
        while(b--){
            a = n - b;
            if(arr[b] == 0 && b % 2 != 0 && a > 1 && arr[a] == 0) break;
        }
        if(b == 0){
            printf("Goldbach's conjecture is wrong.");  
            continue;
        }
        printf("%d = %d + %d\n", n, a, b);
    }
    return 0;
}