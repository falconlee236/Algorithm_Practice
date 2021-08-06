/*11054*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[1001], dp_asc[1001] = {}, dp_desc[1001] = {}, dp[1001] = {};
    for(int i = 1; i <= n; i++) cin >> arr[i];
    dp_asc[1] = 1; dp_desc[n] = 1;
    
    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(arr[j] < arr[i]) dp_asc[i] = max(dp_asc[i], dp_asc[j]);
            if(arr[j] > arr[i]) dp_desc[i] = max(dp_desc[i], dp_desc[j]);
        }
        dp_asc[i]++;
    }
    
    for(int i = n - 1; i > 0; i--){
        for(int j = i + 1; j <= n; j++){
            if(arr[j] < arr[i]) dp_desc[i] = max(dp_desc[i], dp_desc[j]);
        }
        dp_desc[i]++;
    }
    
    for(int i = 1; i <= n; i++) dp[i] = dp_asc[i] + dp_desc[i];
    cout << *max_element(dp, dp + n + 1) - 1;
    return 0;
}
