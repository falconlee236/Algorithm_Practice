/*11653*/
/*Got it!*/
#include <iostream>
#include <cmath>
#define MAX 10000001
using namespace std;

int main(){
    int arr[MAX] = {1, 1};
    for(int i = 2; i < sqrt(MAX); i++){
        if(arr[i] == 1) continue;
        for(int j = i + i; j < MAX; j+=i) arr[j] = 1;
    }
    
    int n; scanf("%d", &n);
    if(n == 1) return 0;
    int i = 2;
    while(n != 1){
        if(arr[i] == 0){
            if(n % i == 0){
                printf("%d\n", i);
                n /= i; 
            }
            else i++;
        }
        else i++;
    }
    return 0;
}