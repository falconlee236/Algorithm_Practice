/*2749*/
/*Cheating*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

mat operator *(mat& a, mat& b){
    int n = a.size();
    mat c(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000000;
        }
    }
    return c;
}

mat mult(mat arr, ll n){
    int size = arr.size();
    mat id(size, vector<ll>(size));
    for(ll i = 0; i < size; i++) id[i][i] = 1;
    
    while(n > 0){
        if(n % 2 == 1) id = id * arr;
        n /= 2;
        arr = arr * arr;
    }
    return id;
}

int main() {
	ll n; cin >> n;
	mat a = {{1, 1}, {1, 0}};
	mat res = mult(a, n - 1);
	cout << (res[1][0] + res[1][1]) % 1000000;
	return 0;
}
