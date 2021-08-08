/*1676*/
/*cheating*/
#include <iostream>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int res = 0, mul = 1;
    for(int i = 1; i <= n; i++){
        mul *= i;
        
        while(mul % 10 == 0){
            mul /= 10;
            res++; 
        }
        mul %= 1000;
    }
    printf("%d", res);
    return 0;
}