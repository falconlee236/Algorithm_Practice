/*2028*/
/*Got it!*/
#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> tuple_data;

int main(){
    int a, b, c; cin >> a >> b >> c;
    queue<tuple_data> q;
    q.emplace(0, 0, c);
    set<tuple_data> visit;
    set<int> res;
    while(!q.empty()){
        tuple_data cur = q.front();
        q.pop();
        int cur_a = get<0>(cur);
        int cur_b = get<1>(cur);
        int cur_c = get<2>(cur);
        
        if(cur_a == 0) res.insert(cur_c);
        
        //1
        tuple_data tmp;
        if(cur_c + cur_b - b >= 0){
            tmp = make_tuple(cur_a, b, cur_c + cur_b - b);
        }
        else{
            tmp = make_tuple(cur_a, cur_c + cur_b, 0);
        }
        
        if(visit.find(tmp) == visit.end()){
            q.push(tmp);
            visit.insert(tmp);
        }
        
        
        if(cur_c + cur_a - a >= 0){
            tmp = make_tuple(a, cur_b, cur_c + cur_a - a);
        }
        else{
            tmp = make_tuple(cur_c + cur_a, cur_b, 0);
        }
        if(visit.find(tmp) == visit.end()){
            q.push(tmp);
            visit.insert(tmp);
        }
        
        //2
        if(cur_b + cur_a - a >= 0){
            tmp = make_tuple(a, cur_b + cur_a - a, cur_c);
        }
        else{
            tmp = make_tuple(cur_b + cur_a, 0, cur_c);
        }
        if(visit.find(tmp) == visit.end()){
            q.push(tmp);
            visit.insert(tmp);
        }
        
        if(cur_b + cur_c - c >= 0){
            tmp = make_tuple(cur_a, cur_b + cur_c - c, c);
        }
        else{
            tmp = make_tuple(cur_a, 0, cur_b + cur_c);
        }
        if(visit.find(tmp) == visit.end()){
            q.push(tmp);
            visit.insert(tmp);
        }
        
        //3
        if(cur_a + cur_b - b >= 0){
            tmp = make_tuple(cur_a + cur_b - b, b, cur_c);
        }
        else{
            tmp = make_tuple(0, cur_a + cur_b, cur_c);
        }
        if(visit.find(tmp) == visit.end()){
            q.push(tmp);
            visit.insert(tmp);
        }
        
        if(cur_a + cur_c - c >= 0){
            tmp = make_tuple(cur_a + cur_c - c, cur_b, c);
        }
        else{
            tmp = make_tuple(0, cur_b, cur_a + cur_c);
        }
        if(visit.find(tmp) == visit.end()){
            q.push(tmp);
            visit.insert(tmp);
        }
    }
    
    for(auto it = res.begin(); it != res.end(); ++it) cout << *it << " ";
}