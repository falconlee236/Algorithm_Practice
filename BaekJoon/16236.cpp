/*16236*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, pair<int, int>> pairs;

int arr[25][25];
bool visit[25][25];

bool cmp(pairs a, pairs b){
    if(a.first == b.first && a.second.first == b.second.first) return a.second.second < b.second.second;
    if(a.first == b.first) return a.second.first < b.second.first;
    return a.first < b.first;
}

int main(){
    int n; cin >> n;
    int row, col, shark_size = 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                row = i;
                col = j;
                visit[i][j] = true;
            }
        }
    }
    int ans = 0;
    int food_size = 0;
    int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(1){
        vector<pairs> v;
        queue<pairs> q;
        q.push({0, {row, col}});
        while(!q.empty()){
            int x = q.front().second.first, y = q.front().second.second;
            int dist = q.front().first;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + pos[i][0], ny = y + pos[i][1];
                if(0 <= nx && nx < n && 0 <= ny && ny < n){
                    if(!visit[nx][ny]){
                        visit[nx][ny] = true;
                        if(arr[nx][ny] < shark_size && arr[nx][ny] != 0) v.push_back({dist + 1, {nx, ny}});
                        else if(arr[nx][ny] > shark_size) continue;
                        q.push({dist + 1, {nx, ny}});
                    }
                }
            }
        }
        
        if(v.size() == 0){
            cout << ans;
            return 0;
        }
        else{
            sort(v.begin(), v.end(), cmp);
            ans += v[0].first;
            arr[row][col] = 0;
            row = v[0].second.first;
            col = v[0].second.second;
            fill(visit[0], visit[0] + 25 * 25, false);
            arr[row][col] = 9;
            visit[row][col] = true;
            food_size++;
        }
        
        if(food_size == shark_size){
            shark_size++;
            food_size = 0;
        }
    }
    
}