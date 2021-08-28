/*2775*/
/*Got it!*/
#include <iostream>
using namespace std;

int arr[15][15];

int main() {
    for(int i = 1; i <= 14; i++) arr[0][i] = i;
    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            for(int k = j; k >= 1; k--){
                arr[i][j] += arr[i - 1][k];
            }
        }
    }
    
    int t; cin >> t;
    while(t--){
        int k, n; cin >> k >> n;
        cout << arr[k][n] << "\n";
    }
	return 0;
}
