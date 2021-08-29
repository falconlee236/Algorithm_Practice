/*4386*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

typedef struct{
    double x;
    double y;
}Point;

Point pos[110];
int root[110];
map<pair<double, double>, int> mp;

double cord(Point a, Point b){
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int find(int num){
    if(num == root[num]) return num;
    return root[num] = find(root[num]);
}

bool merge(int a, int b){
    int u = find(a), v = find(b);
    if(u == v) return false;
    
    if(u < v) root[v] = u;
    else root[u] = v;
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pos[i].x >> pos[i].y;
        mp[{pos[i].x, pos[i].y}] = i;
        root[i] = i;
    }
    vector<pair<double, pair<int, int>>> v;
    for(int i = 1; i <= n - 1; i++){
        for(int j = i + 1; j <= n; j++){
            v.push_back({cord(pos[i], pos[j]), {mp[{pos[i].x, pos[i].y}], mp[{pos[j].x, pos[j].y}]}});
        }
    }
    
    sort(v.begin(), v.end());
    double ans = 0;
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(cnt == n - 1) break;
        double cost = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        if(merge(x, y)){
            cnt++;
            ans += cost;
        }
    }
    cout.precision(2);
    cout << fixed;
    cout << ans;
    return 0;
}