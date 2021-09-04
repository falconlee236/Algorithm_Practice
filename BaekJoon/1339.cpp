/*1339*/
/*Got it!*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> strs;
vector<int> match;
map<int, int> mp;
bool alpha[26], visit[10];
int ans = -1, n;

void cal(){
    int res = 0;
    for(int i = 0; i < n; i++){
        int tmp = 0, p = 1;
        for(int j = strs[i].size() - 1; j >= 0; j--){
            tmp += (match[mp[strs[i][j] - 'A']] * p);
            p *= 10;
        }
        res += tmp;
    }
    ans = max(ans, res);
}

void func(int cnt){
    if(cnt == 0){
        cal();
        return;
    }
    for(int i = 0; i < 10; i++){
        if(!visit[i]){
            visit[i] = true;
            match.push_back(i);
            func(cnt - 1);
            visit[i] = false;
            match.pop_back();
        }
    }
}

int main(){
    cin >> n;
    int count = 0;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        strs.push_back(str);
        for(int j = 0; str[j] != '\0'; j++){
            int idx = str[j] - 'A';
            if(!alpha[idx]){
                alpha[idx] = true;
                mp[idx] = count++;
            }
        }
    }
    func(count);
    cout << ans;
    return 0;
}