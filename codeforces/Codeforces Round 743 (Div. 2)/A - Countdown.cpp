/*09:00*/
#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char arr[101];
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = n - 1; i >= 0; i--){
            sum += (arr[i] - '0');
            if(arr[i] != '0' && i != n - 1) cnt++;
        }
        cout << sum + cnt << "\n";
    }
	return 0;
}
