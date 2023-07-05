#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ab;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ab.emplace_back(a, a + b);
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto f = [&](int i, int j)
    {
        auto [ai, aj] = ab[i];
        auto [bi, bj] = ab[j];
        return (long long)ai * bj > (long long)aj * bi;
    };
    stable_sort(p.begin(), p.end(), f);
    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << " \n"[i == n - 1];
}