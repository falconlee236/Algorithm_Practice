/*1476*/
/*Got it!*/
#include <iostream>
using namespace std;

int main(){
    int e, s, m; scanf("%d %d %d", &e, &s, &m);
    int arr[3] = {1, 1, 1};
    int cnt = 0;
    while(1){
        if(e == arr[0] && s == arr[1] && m == arr[2]) break;
        arr[0]++; arr[1]++; arr[2]++;
        if(arr[0] > 15) arr[0] %= 15;
        if(arr[1] > 28) arr[1] %= 28;
        if(arr[2] > 19) arr[2] %= 19;
        cnt++;
    }
    printf("%d", ++cnt);
    return 0;
}