/*1107*/
/*Cheating*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    string str; getline(cin, str);
	int m; scanf("%d", &m);
	if(m == 10){
	    cout << abs(stoi(str) - 100);
	    return 0;
	}
	
	vector<char> v;
	for(int i = 0; i < m; i++){
	    char num; cin >> num;
	    v.push_back(num);
	}
	
	int ans = 1000000000;
	for(int i = 0; i <= 1000000; i++){
	    string num = to_string(i);
	    bool flag = true;
	    for(int j = 0; j < v.size(); j++){
	        if(num.find(v[j]) != string::npos){
	            flag = false;
	            break;
	        }
	    }
	    
	    if(flag){
	        int a = abs(100 - stoi(str));
	        int b = num.size() + abs(stoi(num) - stoi(str));
	        ans = min(ans, min(a, b));
	    }
	}
	printf("%d", ans);
	return 0;
}
