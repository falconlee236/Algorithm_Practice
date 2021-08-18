/*1697*/
/*Cheating*/
#include <iostream>
#include <queue>
using namespace std;

int visit[100010];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	queue<pair<int, int>> q;
	int res = 0;
	q.emplace(n, 0);
	
	while(!q.empty()){
	    int locate = q.front().first;
	    int cost = q.front().second;
	    q.pop();
	    
	    if(locate == k){
	        res = cost;
	        break;
	    }
	    
	    int a = locate - 1;
	    int b = locate + 1;
	    int c = locate * 2;
	    
	    if(a >= 0 && !visit[a]){
	        visit[a] = 1;
	        q.emplace(a, cost + 1);
	    }
	    
	    if(b <= k && !visit[b]){
	        visit[b] = 1;
	        q.emplace(b, cost + 1);
	    }
	    
	    if(c <= k + 1 && !visit[c]){
	        visit[c] = 1;
	        q.emplace(c, cost + 1);
	    }
	}
	
	printf("%d", res);
	return 0;
}
