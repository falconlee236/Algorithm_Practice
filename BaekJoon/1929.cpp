/*1929*/
/*Got it!*/
#include <iostream>
#include <cmath>

#define MAX 10000001
using namespace std;

int main() {
    int m, n; scanf("%d %d", &m, &n);
	bool arr[MAX] = {true, true, }; // 1은 소수가 아니다.
	for(int i = 2; i <= sqrt(MAX); i++){
	    if(arr[i]) continue;
	    for(int j = i + i; j <= MAX; j += i) arr[j] = true;
	}
	
	for(int i = m; i <= n; i++){
	    if(!arr[i]) printf("%d\n", i);
	}
	return 0;
}
