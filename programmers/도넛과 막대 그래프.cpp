#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0), inbound(1000001, 0), outbound(1000001, 0);
    vector<vector<int>> g(1000001);
    int len = -1;
    for(auto v : edges){
        int from = v[0], to = v[1];
        len = max(len, from);
        len = max(len, to);
        g[from].push_back(to);
        outbound[from]++;
        inbound[to]++;
    }
    
    vector<int> visited(len + 1, 0);
    vector<int> eight;
    int target = 0;
    for(int i = 1; i <= len; i++){
        if (inbound[i] == 0 && outbound[i] > 1) target = i;
        if (inbound[i] > 0 && outbound[i] == 2){
            answer[3]++;
            visited[i] = 2;
        }
    }
    
    visited[target] = 1;
    answer[0] = target;
    for(int start : g[target]){
        queue<int> q;
        if (visited[start] == 2) continue;
        visited[start] = 1;
        q.push(start);
        bool check = true;
        while(q.size()){
            int top = q.front();
            q.pop();
            for(int node : g[top]){
                if (visited[node] == 2) {
                    check = false;
                    break;
                }
                if (visited[node] == 1) {
                    answer[1]++;
                    check = false;
                    break;
                }
                q.push(node);
                visited[node] = 1;
            }
        }
        if (check) answer[2]++;
    }
    return answer;
}