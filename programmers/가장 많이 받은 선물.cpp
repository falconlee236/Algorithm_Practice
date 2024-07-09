#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> mp;
    vector<int> cost(friends.size(), 0);
    int info[51][51] = {0, };
    
    for(int i = 0; i < friends.size(); i++){
        mp[friends[i]] = i;
    }
    
    for(int i = 0; i < gifts.size(); i++){
        istringstream iss(gifts[i]);
        string buf;
        vector<string> v;
        while(getline(iss, buf, ' ')){
            v.push_back(buf);
        }
        int from = mp[v[0]], to = mp[v[1]];
        info[from][to]++;
        cost[from]++;
        cost[to]--;
    }
    
    for(string a : friends){
        int tmp = 0;
        for(string b : friends){
            if (a == b) continue;
            int from = mp[a], to = mp[b];
            if ((info[from][to] == info[to][from] && cost[from] > cost[to]) 
                || info[from][to] > info[to][from]) tmp++;
        }
        answer = max(answer, tmp);
    }
    return answer;
}