#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool cmp(string &a, string &b){
    if (a.length() != b.length()) return a.length() < b.length();
    int sum_a = 0, sum_b = 0;
    for(int i = 0; i < a.length(); i++){
        if (isalpha(a[i]) == 0) sum_a += a[i] - '0';
        if (isalpha(b[i]) == 0) sum_b += b[i] - '0';
    }
    if (sum_a != sum_b) return sum_a < sum_b;
    for(int i = 0; i < a.length(); i++){
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector <string> arr;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i = 0; i < n; i++) cout << arr[i] << "\n";
}