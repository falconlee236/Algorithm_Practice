#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 1000;
    for(int i = 1; i <= 1000; i++){
        string tmp = s.substr(0, i), ans;
        int cnt = 1;
        for(size_t j = i; j < s.length(); j+=i){
            if (s.substr(j, i) == tmp) cnt++;
            else {
                if (cnt > 1) ans += to_string(cnt);
                ans += tmp;
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt > 1) ans += to_string(cnt);
        ans += tmp;
        answer = min(answer, (int)ans.length());
    }
    return answer;
}