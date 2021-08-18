/*10971*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int cost[11][11], visit[11];
int n, res = 100000000, cnt, init;

void dfs(int start, int cost_sum, int cnt){
    visit[start] = 1;
    if(cnt == n && cost[start][init]){
        res = min(res, cost_sum + cost[start][init]);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visit[i] && cost[start][i] > 0){
            int sub_sum = cost_sum + cost[start][i];
            if(sub_sum < res) dfs(i, sub_sum, cnt + 1);
            visit[i] = 0;
        }
    }
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) visit[i] = 0;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= n; j++) scanf("%d", &cost[i][j]);
	}
	for(int i = 1; i <= n; i++){
	    init = i;
	    dfs(i, 0, 1);
	    visit[i] = 0;
	}
	printf("%d", res);
	return 0;
}
