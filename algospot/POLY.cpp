#include <iostream>
#include <algorithm>
using namespace std;

int cache[101][101];
int poly(int n, int first){
    if(n == first) return 1;
    int& ret = cache[n][first];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; i <= n - first; i++){
        int add = first + i - 1;
        add *= poly(n - first, i);
        add %= 10000000;
        ret += add;
        ret %= 10000000;
    }
    return ret;
}


int main() {
	int t; cin >> t;
	fill(cache[0], cache[0] + 101 * 101, -1);
	while(t--){
	    int n; cin >> n;
	    int res = 0;
	    for(int i = 1; i <= n; i++){
	        res += poly(n, i);
	    }
	    cout << res % 10000000 << "\n";
	}
	return 0;
}
