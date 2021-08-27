#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

bool visit[1000001];

int main(){
    int n; cin >> n;
    queue<tuple<int, int, vector<int>>> q;
    q.emplace(n, 0, vector<int>(1, n));
    visit[n] = true;
    visit[0] = true;
    while(!q.empty()){
        int num = get<0>(q.front());
        int cnt = get<1>(q.front());
        vector<int> v = get<2>(q.front());
        
        if(num == 1){
            printf("%d\n", cnt);
            for(int i = 0; i < v.size(); i++) printf("%d ", v[i]);
            return 0;
        }
        
        q.pop();
        if(num % 2 == 0){
            if(!visit[num / 2]){
                v.push_back(num / 2);
                q.emplace(num / 2, cnt + 1, v);
                v.pop_back();
                visit[num / 2] = true;
            }
        }
        
        if(num % 3 == 0){
            if(!visit[num / 3]){
                v.push_back(num / 3);
                q.emplace(num / 3, cnt + 1, v);
                v.pop_back();
                visit[num / 3] = true;
            }
        }
        
        if(!visit[num - 1]){
            v.push_back(num - 1);
            q.emplace(num - 1, cnt + 1, v);
            visit[num - 1] = true;
        }
    }
	return 0;
}