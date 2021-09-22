/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n], idx[(n << 1) + 1] = {}, odd[n + 1];
        odd[0] = 987654321;
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            idx[a[i]] = i;
        }
        for(int i = 0; i < n; i++){
            cin >> b[i]; 
            idx[b[i]] = i;
        }
        
        for(int i = 1; i <= (n << 1); i += 2){
            odd[i] = idx[i];
            if(i > 1) odd[i] = min(odd[i - 2], idx[i]);
        }
        int ans = 987654321;
        for(int i = 2; i <= (n << 1); i += 2){
            ans = min(ans, idx[i] + odd[i - 1]);
        }

        cout << ans << "\n";
    }
	return 0;
}
