#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int N, cnt;
vector<vector<int>> d;

void cal(const vector<int> &team, vector<int> &res, int depth, int num){
    if (depth == N / 2){
        res[cnt++] = num;
        return;
    }
    for(int i = 0; i < 6; i++) 
        cal(team, res, depth + 1, num + d[team[depth]][i]);
}

vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    d = dice;
    vector<int> a_score((int)pow(6, N/2)), b_score((int)pow(6, N/2)), answer(N/2, 0), arr(N);
    for(int i = 0; i < N; i++)
        arr[i] = (i < N / 2 ? 0 : 1);
    int mx_w = 0;
    do{
        vector<int> a_team, b_team;
        for(int i = 0; i < N; i++){
            if (arr[i]) a_team.push_back(i);
            else b_team.push_back(i);
        }
        cal(a_team, a_score, 0, 0);
        cnt = 0;
        cal(b_team, b_score, 0, 0);
        cnt = 0;
        sort(b_score.begin(), b_score.end());
        int w = 0;
        for(int target : a_score)
            w += lower_bound(b_score.begin(), b_score.end(), target) - b_score.begin();
        if (mx_w < w){
            mx_w = w;
            answer = a_team;
        }
    }while(next_permutation(arr.begin(), arr.end()));
    for(int &x : answer) x++;
    return answer;
}