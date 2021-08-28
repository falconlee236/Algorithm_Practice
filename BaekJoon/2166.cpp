/*2166*/
/*Cheating*/
#include <iostream>
#include <math.h>
using namespace std;

typedef struct{
    double x;
    double y;
}point;

double ccw(point a, point b, point c){
    return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

int main(){
    int n; cin >> n;
    point p[10005];
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    double res = 0;
    for(int i = 1; i < n - 1; i++) res += ccw(p[0], p[i], p[i + 1]);
    cout.precision(1);
	cout << fixed;
	cout << abs(res) / 2;
    return 0;
}