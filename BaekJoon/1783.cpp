/*1783*/
/*Got it!*/
#include <iostream>
using namespace std;

int main(){
    int n, m; scanf("%d %d", &n, &m);
    if(n > 2 && m > 6){
        printf("%d", m - 7 + 5);
    }
    else{
        if(n == 1) printf("1");
        else if(n == 2){
            if(m >= 7) printf("4");
            else printf("%d", (m + 1) / 2);
        }
        else if(n > 2 && m <= 6){
            if(m < 4) printf("%d", m);
            else printf("4");
        }
    }
    return 0;
}