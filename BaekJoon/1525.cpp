/*1525*/
/*Got it!*/
#include <iostream>
#include <string>
#include <tuple>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

set<string> visit;

int main() {
    string puzzle = "";
    int idx = 0;
	for(int i = 0; i < 9; i++){
	    string c; cin >> c;
	    if(c == "0") idx = i;
	    puzzle += c;
	}
    
	queue<tuple<string, int, int>> q;
	q.emplace(puzzle, idx, 0);
	while(!q.empty()){
	    string cur = get<0>(q.front());
	    int pos = get<1>(q.front());
	    int count = get<2>(q.front());
	    if(cur == "123456780"){
	        printf("%d", count);
	        return 0;
	    }
	    q.pop();
	    for(int i = 1; i <= 4; i++){
	        if(i == 1){
	            if(pos + 3 < 9){
	                string temp = cur;
	                swap(temp[pos], temp[pos + 3]);
	                if(visit.find(temp) == visit.end()){
	                    q.emplace(temp, pos + 3, count + 1);
	                    visit.insert(temp);
	                }
	                    
	            }
	        }
	        else if(i == 2){
	            if(pos - 3 > -1){
	                string temp = cur;
	                swap(temp[pos], temp[pos - 3]);
	                if(visit.find(temp) == visit.end()){
	                    q.emplace(temp, pos - 3, count + 1);
	                    visit.insert(temp);
	                }
	            }
	        }
	        else if(i == 3){
	            if(pos % 3 != 0){
	                string temp = cur;
	                swap(temp[pos], temp[pos - 1]);
	                if(visit.find(temp) == visit.end()){
	                    q.emplace(temp, pos - 1, count + 1);
	                    visit.insert(temp);
	                }
	            }
	        }
	        else{
	            if(pos != 2 && pos != 5 && pos != 8){
	                string temp = cur;
	                swap(temp[pos], temp[pos + 1]);
	                if(visit.find(temp) == visit.end()){
	                    q.emplace(temp, pos + 1, count + 1);
	                    visit.insert(temp);
	                }
	            }
	        }
	    }
	}
	
	printf("-1");
	return 0;
	
}
