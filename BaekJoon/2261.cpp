/*2261*/
/*Cheating*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 800000000;

int n;
vector<pair<int, int>> v;

int f(int, int);
int dist(pair<int, int>, pair<int, int>);

int main() {
  scanf("%d", &n);
  v.resize(n);
  for (int i=0; i<n; i++) {
    scanf("%d %d", &v[i].first, &v[i].second);
  }
  sort(v.begin(), v.end());// x축을 기준으로 오름차순 정렬
  printf("%d\n", f(0, n-1));
  return 0;
}

int f(int start, int end) {
  int ret = MAX;
  int ec = end - start + 1;// element count
  if (ec <= 3) {
    for (int i=start; i<end; i++) {
      for (int j=i+1; j<=end; j++) {
        ret = min (ret, dist(v[i], v[j]));
      }
    }// brute-force
  }
  else {
    // 중앙 좌표를 기준으로 왼쪽과 오른쪽 섹션을 분할하여 계산
    int mid = (start + end) / 2;
    int left = f(start, mid-1);
    int right = f(mid+1, end);
    ret = min(left, right);

    vector<pair<int, int>> tmp;
    tmp.push_back({v[mid].second, v[mid].first});

    // 중앙 좌표를 중심으로 왼쪽에 있는 것들 중 가능한 것들을 선별
    for (int i=mid-1; i>=start; i--) {
      if (dist({v[mid].first, 0}, {v[i].first, 0}) >= ret) break;
      tmp.push_back({v[i].second, v[i].first});// y축 순으로 정렬
    }

    // 중앙 좌표를 중심으로 오른쪽에 있는 것들 중 가능한 것들을 선별
    for (int i=mid+1; i<=end; i++) {
      if (dist({v[mid].first, 0}, {v[i].first, 0}) >= ret) break;
      tmp.push_back({v[i].second, v[i].first});// y축 순으로 정렬
    }

    sort(tmp.begin(), tmp.end());// y축 정렬

    // 중앙 좌표와의 거리 중 더 가까운 좌표가 있다면 그 거리를 반환
    for (int i=0; i<tmp.size()-1; i++) {
      for (int j=i+1; j<tmp.size(); j++) {
        if (pow(tmp[i].first - tmp[j].first, 2) >= ret) break;
        ret = min(ret, dist(tmp[i], tmp[j]));
      }
    }
  }
  return ret;
}

int dist(pair<int, int> p1, pair<int, int> p2) {
  return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}