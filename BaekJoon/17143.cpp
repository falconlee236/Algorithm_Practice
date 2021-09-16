/*17143*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef struct{
    int vel;
    int pos;
    int size;
}shark;

shark arr[102][102];

int main(){
    int r, c, m; scanf("%d %d %d", &r, &c, &m);

    for(int i = 0; i < m; i++){
        int a, b, c, d, e; scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        arr[a][b] = {c, d, e};
    }
    
    int ans = 0;
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= r; j++){
            if(arr[j][i].pos != 0){
                ans += arr[j][i].size;
                arr[j][i].vel = 0;
                arr[j][i].pos = 0;
                arr[j][i].size = 0;
                break;
            }
        }
        
        vector<tuple<int, int, shark>> v;
        for(int a = 1; a <= r; a++){
            for(int b = 1; b <= c; b++){
                if(arr[a][b].pos != 0) v.push_back({a, b, arr[a][b]});
            }
        }
        
        for(int k = 0; k < v.size(); k++){
            shark& s = get<2>(v[k]);
            int a = get<0>(v[k]);
            int b = get<1>(v[k]);
            
            if(s.pos == 1){
                int speed = s.vel, tmp = 0, cur = a;
                while(speed > 0){
                    if(tmp % 2 == 0){
                        if(cur - speed < 1){
                            speed -= (cur - 1);
                            cur = 1;
                            tmp++;
                        }
                        else{
                            cur -= speed;
                            speed = 0;
                        }
                    }
                    else{
                        if(cur + speed > r){
                            speed -= (r - 1);
                            cur = r;
                            tmp++;
                        }
                        else{
                            cur += speed;
                            speed = 0;
                        }
                    }
                }
                
                s.pos = (tmp % 2 == 0 ? 1 : 2);
                get<0>(v[k]) = cur;
            }
            
            
            if(arr[a][b].pos == 2 ){
                int speed = arr[a][b].vel, tmp = 0, cur = a;
                while(speed > 0){
                    if(tmp % 2 == 0){
                        if(cur + speed > r){
                            speed -= (r - cur);
                            cur = r;
                            tmp++;
                        }
                        else{
                            cur += speed;
                            speed = 0;
                        }
                    }
                    else{
                        if(cur - speed < 1){
                            speed -= (r - 1);
                            cur = 1;
                            tmp++;
                        }
                        else{
                            cur -= speed;
                            speed = 0;
                        }
                    }
                }
                s.pos = (tmp % 2 == 0 ? 2 : 1);
                get<0>(v[k]) = cur;
            }
            
            if(arr[a][b].pos == 4){
                int speed = arr[a][b].vel, tmp = 0, cur = b;
                while(speed > 0){
                    if(tmp % 2 == 0){
                        if(cur - speed < 1){
                            speed -= (cur - 1);
                            cur = 1;
                            tmp++;
                        }
                        else{
                            cur -= speed;
                            speed = 0;
                        }
                    }
                    else{
                        if(cur + speed > c){
                            speed -= (c - 1);
                            cur = c;
                            tmp++;
                        }
                        else{
                            cur += speed;
                            speed = 0;
                        }
                    }
                }
                s.pos = (tmp % 2 == 0 ? 4 : 3);
                get<1>(v[k]) = cur;
            }
        
            if(arr[a][b].pos == 3){
                int speed = arr[a][b].vel, tmp = 0, cur = b;
                while(speed > 0){
                    if(tmp % 2 == 0){
                        if(cur + speed > c){
                            speed -= (c - cur);
                            cur = c;
                            tmp++;
                        }
                        else{
                            cur += speed;
                            speed = 0;
                        }
                    }
                    else{
                        if(cur - speed < 1){
                            speed -= (c - 1);
                            cur = 1;
                            tmp++;
                        }
                        else{
                            cur -= speed;
                            speed = 0;
                        }
                    }
                }
                s.pos = (tmp % 2 == 0 ? 3 : 4);
                get<1>(v[k]) = cur;
            }
        }
        for(int a = 1; a <= r; a++){
            for(int b = 1; b <= c; b++){
                arr[a][b] = {0, 0, 0};
            }
        }
        
        for(int k = 0; k < v.size(); k++){
            int a = get<0>(v[k]);
            int b = get<1>(v[k]);
            shark s = get<2>(v[k]);
            if(s.size > arr[a][b].size){
                arr[a][b] = s;
            }
        }
    }
    cout << ans;
    return 0;
}