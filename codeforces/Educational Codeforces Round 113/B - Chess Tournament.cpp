#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    char cnt[n];
	    vector<int> v;
	    for(int i = 0; i < n; i++){
	        cin >> cnt[i];
	        if(cnt[i] == '2') v.push_back(i);
	    }
	    
	    if(v.size() == 1 || v.size() == 2) cout << "NO" << "\n";
	    else{
	        cout << "YES" << "\n";
	        vector<string> arr(n, string(n, '='));
	        for(int i = 0; i < n; i++) arr[i][i] = 'X';
	        
	        for(int i = 0; i < v.size(); i++){
	            int cur = v[i], next = v[(i + 1) % v.size()];
	            arr[cur][next] = '+';
	            arr[next][cur] = '-';
	        }
	        
	        for(int i = 0; i < n; i++) cout << arr[i] << "\n";
	    }
	}
	return 0;
}
