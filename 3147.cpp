/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/3147
*/
#include <iostream>

using namespace std;

int main() {
    int h,e,a,o,w,x;
    cin >> h >> e >> a >> o >> w >> x;
    int s1, s2;
    s1 = h+e+a+x;
    s2 = o+w;
    if(s1>=s2){
        cout << "Middle-earth is safe." << endl;
    }
    if(s2>s1){
        cout << "Sauron has returned." << endl;
    }
    return 0;
}

