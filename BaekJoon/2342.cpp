
/*2342*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[100002][5][5];
vector<int> input;
int cost[5][5] = {
    {1, 2, 2, 2, 2},
    {3, 1, 3, 4, 3},
    {3, 3, 1, 3, 4},
    {3, 4, 3, 1, 3},
    {3, 3, 4, 3, 1}
};


int main(){
    while(1){
        int num; cin >> num;
        if(!num) break;
        input.push_back(num);
    }
    int inf = 1e9;
    for(int i = 0; i < 100002; i++){
        for(int j = 0; j < 5; j++){
            fill(dp[i][j], dp[i][j] + 5, inf);
        }
    }
    dp[0][0][0] = 0;
    
    for(int k = 1; k <= input.size(); k++){
        int cur = input[k - 1];
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                dp[k][i][cur] = min(dp[k][i][cur], dp[k - 1][i][j] + cost[j][cur]);
            }
        }
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                dp[k][cur][j] = min(dp[k][cur][j], dp[k - 1][i][j] + cost[i][cur]);
            }
        }
    }
    
    int ans = 1e9;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            ans = min(ans, dp[input.size()][i][j]);
        }
    }
    cout << ans;
    return 0;
}