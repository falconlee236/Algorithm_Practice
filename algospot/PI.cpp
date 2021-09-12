#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;

string test;
int cache[10002];

int classify(int a, int b){
    string m = test.substr(a, b - a + 1);
    if(m == string(m.size(), m[0])) return 1;
    
    bool progressive = true;
    for(int i = 0; i < m.size() - 1; i++){
        if(m[i + 1] - m[i] != m[1] - m[0]) progressive = false;
    }
    
    if(progressive && abs(m[1] - m[0]) == 1) return 2;
    
    bool althernating = true;
    for(int i = 0; i < m.size(); i++){
        if(m[i] != m[i % 2]) althernating = false;
    }
    if(althernating) return 4;
    if(progressive) return 5;
    return 10;
}

int cal(int pos){
    if(pos == test.size()) return 0;
    int& ret = cache[pos];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 3; i < 6; i++){
        if(pos + i <= test.size()) ret = min(ret, cal(pos + i) + classify(pos, pos + i - 1));
    }
    return ret;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> test;
        fill(cache, cache + 10002, -1);
        cout << cal(0) << "\n";
    }
}