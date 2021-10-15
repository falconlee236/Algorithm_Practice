/*5623*/
/*00:24*/
#include <cstdio>
#include <vector>
using namespace std;

int arr[1000][1000];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++) 
	        scanf("%d", &arr[i][j]);
    
    if(n == 2){
        printf("%d %d", arr[0][1] / 2, arr[0][1] / 2);
    }
    else{
        vector<int> v(n);
        v[0] = (arr[0][1] + arr[0][2] - arr[1][2]) / 2;
        for(int i = 1; i < n; i++){
            v[i] = arr[i - 1][i] - v[i - 1];
        }
        for(auto x : v) printf("%d ", x);
    }
	
	
	return 0;
}
