/*10830*/
/*Cheating*/
#include <iostream>
#include <map>
using namespace std;
int n;
typedef struct _mat{
    long long m[5][5] = {};
    _mat operator *(_mat a){
        _mat res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    res.m[i][j] += (m[i][k] * a.m[k][j]);
                }
                res.m[i][j] %= 1000;
            }
        }
        return res;
    }
}Mat;
Mat a;
map<long long, Mat> mp;

Mat func(long long cnt){
    if(cnt == 1) return a;
    if(mp.find(cnt) != mp.end()) return mp[cnt];
    if(cnt % 2 == 1) return mp[cnt] = a * func(cnt - 1);
    return mp[cnt] = func(cnt / 2) * func(cnt / 2);
}

int main() {
	long long b; cin >> n >> b;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a.m[i][j];
	Mat res = func(b);
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < n; j++){
	        cout << res.m[i][j] % 1000 << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
