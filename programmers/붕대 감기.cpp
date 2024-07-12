#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health, prev_time = 0;
    for(auto v : attacks){
        int t = v[0], damage = v[1], duration = t - prev_time - 1;
        answer = min(health, answer + duration * bandage[1] + (duration / bandage[0]) * bandage[2]);
        answer -= damage;
        prev_time = t;
        if (answer <= 0) break;
    }
    return (answer <= 0 ? -1 : answer);
}