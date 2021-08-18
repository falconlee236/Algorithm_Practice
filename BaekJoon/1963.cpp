/*1963*/
/*Got it!*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int prime[10000];

int main() {
    for(int i = 0; i < 10000; i++) prime[i] = 1;
    prime[0] = 0; prime[1] = 0;
	for(int i = 2; i * i <= 10000; i++){
	    if(!prime[i]) continue;
	    for(int j = i + i; j < 10000; j += i) prime[j] = 0;
	}
	
	int t; scanf("%d", &t);
	while(t--){
	    int a, b; scanf("%d %d", &a, &b);
	    int visit[10000];
	    for(int i = 0; i < 10000; i++) visit[i] = 0;
	    int res = 0;
	    queue<pair<int, int>> q;
	    q.emplace(a, 0);
	    while(!q.empty()){
	        int p = q.front().first, cost = q.front().second;
	        if(p == b){
	            res = cost;
	            break;
	        }
	        
	        string str = to_string(p);
	        q.pop();
	        for(int i = 1; i < 10; i++){
	            str[0] = (char)(i + '0');
	            int num = stoi(str);
	            if(prime[num] && !visit[num]){
	                visit[num] = 1;
	                q.emplace(num, cost + 1);
	            }
	        }
	        
	        str = to_string(p);
	        for(int i = 0; i < 10; i++){
	            str[1] = (char)(i + '0');
	            int num = stoi(str);
	            if(prime[num] && !visit[num]){
	                visit[num] = 1;
	                q.emplace(num, cost + 1);
	            }
	        }
	        
	        str = to_string(p);
	        for(int i = 0; i < 10; i++){
	            str[2] = (char)(i + '0');
	            int num = stoi(str);
	            if(prime[num] && !visit[num]){
	                visit[num] = 1;
	                q.emplace(num, cost + 1);
	            }
	        }
	        
	        str = to_string(p);
	        for(int i = 0; i < 10; i++){
	            str[3] = (char)(i + '0');
	            int num = stoi(str);
	            if(prime[num] && !visit[num]){
	                visit[num] = 1;
	                q.emplace(num, cost + 1);
	            }
	        }
	    }
	    printf("%d\n", res);
	}
	return 0;
}
