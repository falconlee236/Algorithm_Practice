#include <iostream>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	float total_grade = 0; float total_num = 0;
    for(int i = 0; i < 20; i++){
        string name, grade; float num;
        cin >> name >> num >> grade;
		if (grade == "A+"){
			total_grade +=  num * 4.5;
			total_num += num;
		} else if (grade == "A0"){
			total_grade += num * 4.0;
			total_num += num;
		} else if (grade == "B+"){
			total_grade += num * 3.5;
			total_num += num;
		} else if (grade == "B0"){
			total_grade += num * 3.0;
			total_num += num;
		} else if (grade == "C+"){
			total_grade += num * 2.5;
			total_num += num;
		} else if (grade == "C0"){
			total_grade += num * 2.0;
			total_num += num;
		} else if (grade == "D+"){
			total_grade += num * 1.5;
			total_num += num;
		} else if (grade == "D0"){
			total_grade += num * 1.0;
			total_num += num;
		} else if (grade == "F"){
			total_grade += num * 0.0;
			total_num += num;
		}
	}
    cout << total_grade / total_num;
}
