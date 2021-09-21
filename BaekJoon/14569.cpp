/*14569*/
/*Got it!*/
/*39:42*/
#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ull sub[1001] = {0, };
    ull student[10001] = {0, };
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        for(int j = 0; j < num; j++){
            int p; cin >> p;
            sub[i] |= ((ull)1 << p);
        }
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int num; cin >> num;
        for(int j = 0; j < num; j++){
            int p; cin >> p;
            student[i] |= ((ull)1 << p);
        }
    }
    
    for(int i = 0; i < m; i++){
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(sub[j] == (student[i] & sub[j])) ans++;
        }
        cout << ans << "\n";
    }
}