/*
    Dalton Adiers - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1028
*/
#include <iostream>

using namespace std;

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int main() {
    int x;
    cin >> x;
    for(int i=0; i<x;i++){
        int a,b;
        cin >> a >>b;
        cout << mdc(a,b) << endl;
    }
    return 0;
}
