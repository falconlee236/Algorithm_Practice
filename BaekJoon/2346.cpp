#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<pii> arr;
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int num; cin >> num;
    arr.push_back({i + 1, num});
  }
  int idx = 0;
  int N = n;
  while (1){
    int cur = arr[idx].first;
    int next = arr[idx].second;
    cout << cur << " ";
    arr[idx].second = 0;
    N--;
    if (N == 0) break;
    if (next > 0){
      while (next--){
        idx = (idx + 1) % n;
        if (arr[idx].second == 0) next++;
      }
    }
    else if (next < 0){
      next = -next;
      while (next--){
        if (idx == 0) idx = n;
        idx--;
        if (arr[idx].second == 0) next++;
      }
    }
  }
  return 0;
}
