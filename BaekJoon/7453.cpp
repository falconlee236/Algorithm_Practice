/*7453*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[4000];
int b[4000];
int c[4000];
int d[4000];

vector<long long> v1, v2;

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v1.push_back(a[i] + b[j]);
            v2.push_back(c[i] + d[j]);
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long ans = 0;
    for(int i = 0; i < v1.size(); i++){
        ans += (upper_bound(v2.begin(), v2.end(), 0 - v1[i]) - lower_bound(v2.begin(), v2.end(), 0 - v1[i]));
    }
    printf("%lld", ans);
	return 0;
}