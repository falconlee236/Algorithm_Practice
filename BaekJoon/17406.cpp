// 17406
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, ans = 0xFFFFFF; cin >> n >> m >> k;
    int rot[k][3], arr[n + 1][m + 1];
    int line[k];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    for(int i = 0; i < k; i++){
        line[i] = i;
        cin >> rot[i][0] >> rot[i][1] >> rot[i][2];
    }
    do{
        int tmp[n + 1][m + 1], base[n + 1][m + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) {
                tmp[i][j] = arr[i][j];
                base[i][j] = arr[i][j];
            }
        }
        for(int t = 0; t < k; t++){
            int r = rot[line[t]][0], c = rot[line[t]][1], s = rot[line[t]][2];
            int s_x = r - s, s_y = c - s, e_x = r + s, e_y = c + s;
            int m_x = (s_x + e_x) / 2 - ((s_x + e_x - 1) % 2), m_y = (s_y + e_y) / 2 - ((s_y + e_y - 1) % 2);
            //top
            for(int i = s_x, cnt = 0; i < s_x + m_x; i++, cnt++){
                for(int j = s_y + 1 + cnt; j <= e_y - cnt; j++) tmp[i][j] = base[i][j - 1];
            }
            //bottom
            for(int i = e_x, cnt = 0; i > e_x - m_x; i--, cnt++){
                for(int j = e_y - 1 - cnt; j >= s_y + cnt; j--) tmp[i][j] = base[i][j + 1];
            }
            //right
            for(int i = e_y, cnt = 0; i > e_y - m_y; i--, cnt++){
                for(int j = s_x + 1 + cnt; j <= e_x - cnt; j++) tmp[j][i] = base[j - 1][i];
            }
            // left
            for (int i = s_y, cnt = 0; i < s_y + m_y; i++, cnt++){
                for (int j = e_x - 1 - cnt; j >= s_x + cnt; j--) tmp[j][i] = base[j + 1][i];
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++) base[i][j] = tmp[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            int tmp_ans = 0;
            for (int j = 1; j <= m; j++) tmp_ans += tmp[i][j];
            ans = min(ans, tmp_ans);
        }
    }while(next_permutation(line, line + k));
    cout << ans;
}