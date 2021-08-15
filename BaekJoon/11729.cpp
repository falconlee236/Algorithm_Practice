/*11729*/
/*Cheating*/
#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

void hanoi(int start, int end, int way, int n){
    if(n == 1){
        v.push_back(make_pair(start, end));
        cnt++;
        return;
    }
    hanoi(start, way, end, n - 1);
    hanoi(start, end, way, 1);
    hanoi(way, end, start, n - 1);
}

int main(){
    int n; scanf("%d", &n);
    hanoi(1, 3, 2, n);
    printf("%d\n", cnt);
    for(auto it = v.begin(); it != v.end(); it++) printf("%d %d\n", it->first, it->second);
    return 0;
}