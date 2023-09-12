#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void){
    string stat; cin >> stat;
    vector<int> numbers;
    vector<char> ops;
    int i, start = 0;
    for(i = 0; i < stat.length(); i++){
        if (stat[i] == '-' || stat[i] == '+'){
            numbers.push_back(atoi(stat.substr(start, i - start).c_str()));
            ops.push_back(stat[i]);
            start = i + 1;
        }
    }
    numbers.push_back(atoi(stat.substr(start, i - start).c_str()));
    int res = numbers[0];
    bool flag = true;
    for(int k = 0; k < ops.size(); k++){
        if (ops[k] == '-')
            flag = false;
        if (flag)
            res += numbers[k + 1];
        else
            res -= numbers[k + 1];
    }
    cout << res << "\n";
}