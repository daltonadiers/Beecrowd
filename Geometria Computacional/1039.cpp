#include <iostream>
#include <math.h>

using namespace std;

string solve(int r1, int x1, int y1, int r2, int x2, int y2){
    double distSq = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    if (distSq + r2 == r1 || distSq + r2 < r1)return "RICO";
    else return "MORTO";
}

int main(){
    int r1, x1, y1, r2, x2, y2;
    while(cin >> r1>>x1>>y1>>r2>>x2>>y2)cout << solve(r1, x1, y1, r2, x2, y2) << "\n";
    return 0;
}