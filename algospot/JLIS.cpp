#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();

int n, m, A[100], B[100];
int dp[101][101];

int jlis(int idxA, int idxB){
    int& ret = dp[idxA + 1][idxB + 1];
    if(ret != -1) return ret;
    
    ret = 2;
    long long a = (idxA == -1 ? NEGINF : A[idxA]);
    long long b = (idxB == -1 ? NEGINF : B[idxB]);
    long long maxElement = max(a, b);
    
    for(int nextA = idxA + 1; nextA < n; nextA++){
        if(maxElement < A[nextA]) ret = max(ret, jlis(nextA, idxB) + 1);
    }
    for(int nextB = idxB + 1; nextB < m; nextB++){
        if(maxElement < B[nextB]) ret = max(ret, jlis(idxA, nextB) + 1);
    }
    return ret;
}

int main() {
	int t; cin >> t;
	while(t--){
	    cin >> n >> m;
	    fill(dp[0], dp[0] + 101 * 101, -1);
	    for(int i = 0; i < n; i++) cin >> A[i];
	    for(int i = 0; i < m; i++) cin >> B[i];
	    cout << jlis(-1, -1) - 2 << "\n";
	}
	return 0;
}
