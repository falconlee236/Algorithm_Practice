#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string line; int cnt;
    while (cin >> line >> cnt){
        int tmp = 0;
        string tmp_line(line.begin(), line.end());
        do{
            tmp++;
            if (cnt == tmp) break;
        } while (next_permutation(tmp_line.begin(), tmp_line.end()));
        cout << line << " " << cnt << " = " << (cnt != 1 && tmp_line == line ? "No permutation" : tmp_line) << "\n";
    }
}