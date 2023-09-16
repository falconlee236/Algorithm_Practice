#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(void){
    int n, k; cin >> n >> k;
    queue<pair<int, int>> q;
    set<int> s;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        q.push({num, 0});
        s.insert(num);
    }
    long long res = 0;
    while (k > 0){
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (s.find(cur + 1) == s.end()){
            q.push({cur + 1, dist + 1});
            s.insert(cur + 1);
            if (k > 0) res += (long long)(dist + 1);
            k--;
        }
        if (s.find(cur - 1) == s.end()){
            q.push({cur - 1, dist + 1});
            s.insert(cur - 1);
            if (k > 0) res += (long long)(dist + 1);
            k--;
        }
    }
    cout << res << "\n";
}