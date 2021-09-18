#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int n;
int v[101], cache[101][11], part[101], ppart[101];

int sum(int a, int b){
    int p_sum = (a == 0 ? part[b] : part[b] - part[a - 1]);
    int pp_sum = (a == 0 ? ppart[b] : ppart[b] - ppart[a - 1]);
    int m = int(0.5 + (double)p_sum / (b - a + 1));
    return pp_sum - 2 * m * p_sum + (b - a + 1) * m * m;
}

int quantize(int pos, int size){
    if(pos == n) return 0;
    if(size == 0) return INF;
    int& ret = cache[pos][size];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 1; pos + i <= n; i++){
        ret = min(ret, quantize(pos + i, size - 1) + sum(pos, pos + i - 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
	    int s; cin >> n >> s;
	    fill(v, v + 101, 0);
	    fill(cache[0], cache[0] + 101 * 11, -1);
	    fill(part, part + 101, 0);
	    fill(ppart, ppart + 101, 0);
	    for(int i = 0; i < n; i++) cin >> v[i];
	    sort(v, v + n);
	    part[0] = v[0];
	    ppart[0] = v[0] * v[0];
	    for(int i = 1; i < n; i++){
	        part[i] = part[i - 1] + v[i];
	        ppart[i] = ppart[i - 1] + v[i] * v[i];
	    }
	    cout << quantize(0, s) << "\n";
	}
	return 0;
}